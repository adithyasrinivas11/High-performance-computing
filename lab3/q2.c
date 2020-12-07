#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[100000],b[100000], c[100000],c1,sum;
	for(int i=0;i<100000;i++)
	{	a[i]= pow(2,15)+rand()+0.13246549884;//rand();
		b[i]= pow(2,16)+rand()+0.75245496088;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
	
		double start, end;
	start = omp_get_wtime();
	// Beginning of parallel region 
	#pragma omp parallel
	{
	c1=0;
	
	#pragma omp parallel for
	for(int i=0;i<100000;i++)
	{
		c[i]=a[i]*b[i];
		c1+=c[i];
	}
	
	#pragma omp critical
		sum+=c1;
	
	}
	// Ending of parallel region 
	end = omp_get_wtime();
	/*for(int i=0;i<100000;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	printf("\n the time taken is:: %f\n",end-start);
} 

