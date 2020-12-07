
#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[100][100],b[100][100], c[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{	
			a[i][j]= pow(2,15)+rand()+0.132465498;//rand();
			b[i][j]= pow(2,13)+rand()+0.1684321846;//rand();
			//printf("%f   %f\n",a[i],b[i]);
		}	
	}
	
	int B=9;
	// Beginning of parallel region 
	double start, end;
  	start = omp_get_wtime();
	#pragma omp parallel 
	{ 
		double max=omp_get_max_threads();
/*		double width=256/max;*/
		int num=omp_get_thread_num();
/*		printf("Hello World... from thread = %d  \n", num+1);*/
/*		 for(int i=num*width;i<(num+1)*width && i<256;i++)*/
/*		 	c[i]=a[i]+b[i];*/
		#pragma omp for
		for(int jj=0;jj<100;jj=jj+B)
		for(int ii=0;ii<100;ii=ii+B)
		for(int i=0;i<100;i++)
		 {
		 	int z;
		 	if(jj+B<100)
		 		z=jj+B;
		 	else
		 		z=100;
		 	for(int j=jj;j<z;j++)
		 	{
		 		
		 		double r=0;
		 		int z1;
		 		if(ii+B<100)
		 			z1=ii+B;
		 		else
		 			z1=100;
		 			
		 		//c[i][j]=0;
		 		for(int k=ii;k<z1;k++)
		 		{
		 			r+=a[i][k]*b[k][j];		//coloumn  major order.
		 		}
		 		c[i][j]+=r;
		 	//printf("%d  %d\n",i,j);
		 	}
		}
		 	
	} 
	// Ending of parallel region 
	end = omp_get_wtime();
	/*for(int i=0;i<256;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	
	printf("\n the time taken is:: %f\n",end-start);
} 


