%%cu
#include <stdio.h>
#include <time.h>
#include <fstream>
#include<iostream>

using namespace std;
#define N 64
#define thread_count 32
#define K 3					// # clusters
#define MAX_ITER 10

__device__ float distance(float x1,float y1, float x2,float y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

__global__ void kMeansClusterAssignment(float *d_datapoint_x,float *d_datapoint_y, int *d_clust_assn, float *d_centroid_x,float *d_centroid_y)
{

	const int idx = blockIdx.x*blockDim.x + threadIdx.x;


	if (idx >= N)
		return;

	float min_dist = INFINITY;
	int closest_centroid = 0;

	for(int c = 0; c<K;++c)
	{
		float dist = distance(d_datapoint_x[idx],d_datapoint_y[idx],d_centroid_x[c],d_centroid_y[c]);

		if(dist < min_dist)
		{
			min_dist = dist;
		closest_centroid=c;
		}
	}


	d_clust_assn[idx]=closest_centroid;
}


void kMeansCentroidUpdate(float *d_datapoint_x,float *d_datapoint_y, int *d_clust_assn, float *d_centroid_x,float *d_centroid_y, int *d_clust_sizes)
{


	const int idx = blockIdx.x*blockDim.x + threadIdx.x;


	if (idx >= N)
		return;


	const int s_idx = threadIdx.x;


	__shared__ float s_datapoint_x[thread_count];
	__shared__ float s_datapoint_y[thread_count];

	s_datapoint_x[s_idx]= d_datapoint_x[idx];
	s_datapoint_y[s_idx]= d_datapoint_y[idx];

	__shared__ int s_clust_assn[thread_count];
	s_clust_assn[s_idx] = d_clust_assn[idx];

	__syncthreads();


	if(s_idx==0)
	{
		float b_clust_datapoint_sum_x[K]={0};
		float b_clust_datapoint_sum_y[K]={0};
		int b_clust_sizes[K]={0};

		for(int j=0; j< blockDim.x; ++j)
		{
			int clust_id = s_clust_assn[j];
			b_clust_datapoint_sum_x[clust_id]+=s_datapoint_x[j];
			b_clust_datapoint_sum_x[clust_id]+=s_datapoint_y[j];
			b_clust_sizes[clust_id]+=1;
		}


		for(int z=0; z < K; ++z)
		{
			atomicAdd(&d_centroid_x[z],b_clust_datapoint_sum_x[z]);
			atomicAdd(&d_centroid_y[z],b_clust_datapoint_sum_y[z]);
			atomicAdd(&d_clust_sizes[z],b_clust_sizes[z]);
		}
	}

	__syncthreads();


	if(idx < K)
	{
		d_centroid_x[idx] = d_centroid_x[idx]/d_clust_sizes[idx]; 
		d_centroid_y[idx] = d_centroid_y[idx]/d_clust_sizes[idx]; 
	}

}


int main()
{


	float *d_datapoint_x=0,*d_datapoint_y=0;
	int *d_clust_assn = 0;
	float *d_centroid_x =0,*d_centroid_y =0;
	int *d_clust_sizes=0;

	cudaMalloc(&d_datapoint_x, N*sizeof(float));
	cudaMalloc(&d_datapoint_y, N*sizeof(float));

	cudaMalloc(&d_clust_assn,N*sizeof(int));

	cudaMalloc(&d_centroid_x,K*sizeof(float));
	cudaMalloc(&d_centroid_y,K*sizeof(float));

	cudaMalloc(&d_clust_sizes,K*sizeof(float));

	float *h_centroid_x = (float*)malloc(K*sizeof(float));
	float *h_centroid_y = (float*)malloc(K*sizeof(float));

	float *h_datapoint_x = (float*)malloc(N*sizeof(float));
	float *h_datapoint_y = (float*)malloc(N*sizeof(float));

	int *h_clust_sizes = (int*)malloc(K*sizeof(int));

	srand(time(0));


	for(int c=0;c<K;++c)
	{
		h_centroid_x[c]=(float) rand() / (double)RAND_MAX;
		h_centroid_y[c]=(float) rand() / (double)RAND_MAX;
		printf("%f %f\n", h_centroid_x[c],h_centroid_y[c]);
		h_clust_sizes[c]=0;
	}



	char data[100];
	int z1=0,z2=0,x1,x2,cc=0,i=0;
	ifstream infile; 
	infile.open("data_pcap.csv");
	while( !infile.eof())
	{
		infile >> data; 
		if(strcmp(data,",") != 0)			
		{
			if(cc%3 ==0)
			{
				x1=atoi(data); 		
				h_datapoint_x[i]=x1;
				z1=1;
			}
			if(cc%3 ==1)
			{
				x2=atoi(data); 	
				z2=1;	
				h_datapoint_y[i]=x2;
			}
			if(z1 ==1 && z2== 1)
			{
				z1=0;
				z2=0;
				i++;
			}
			cc++;
		}	
	}

	cudaMemcpy(d_centroid_x,h_centroid_x,K*sizeof(float),cudaMemcpyHostToDevice);
	cudaMemcpy(d_centroid_y,h_centroid_y,K*sizeof(float),cudaMemcpyHostToDevice);

	cudaMemcpy(d_datapoint_x,h_datapoint_x,N*sizeof(float),cudaMemcpyHostToDevice);
	cudaMemcpy(d_datapoint_y,h_datapoint_y,N*sizeof(float),cudaMemcpyHostToDevice);

	cudaMemcpy(d_clust_sizes,h_clust_sizes,K*sizeof(int),cudaMemcpyHostToDevice);

	int cur_iter = 1;
	kMeansClusterAssignment<<<(N+thread_count-1)/thread_count,thread_count>>>(d_datapoint_x,d_datapoint_y,d_clust_assn,d_centroid_x,d_centroid_y);


	cudaMemcpy(h_centroid_x,d_centroid_x,K*sizeof(float),cudaMemcpyDeviceToHost);
	cudaMemcpy(h_centroid_y,d_centroid_y,K*sizeof(float),cudaMemcpyDeviceToHost);

	while(cur_iter < MAX_ITER)
	{
	/*
	for(int i =0; i < K; ++i)
		printf("Iteration %d: centroid %d: %f  %f\n",cur_iter,i,h_centroid_x[i],h_centroid_y[i]);
	*/
	kMeansCentroidUpdate<<<(N+thread_count-1)/thread_count,thread_count>>>(d_datapoint_x,d_datapoint_y,d_clust_assn,d_centroid_x,d_centroid_y,d_clust_sizes);

	cur_iter+=1;
	}

	cudaFree(d_datapoint_x);
	cudaFree(d_datapoint_y);

	cudaFree(d_clust_assn);

	cudaFree(d_centroid_x);
	cudaFree(d_centroid_y);

	cudaFree(d_clust_sizes);

	free(h_centroid_x);
	free(h_centroid_y);

	free(h_datapoint_x);
	free(h_datapoint_y);
	free(h_clust_sizes);

	return 0;
}
