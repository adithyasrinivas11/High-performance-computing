#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[256],b[256], c[256];
	for(int i=0;i<256;i++)
	{	a[i]= i;//rand();
		b[i]= i;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
	
	
	// Beginning of parallel region 
	clock_t start, end;
  	start = clock();
	#pragma omp parallel 
	{ 
		double max=omp_get_max_threads();
		double width=256/max;
		double num=omp_get_thread_num();
		printf("Hello World... from thread = %d  \n", num+1);
		 for(int i=num*width;i<(num+1)*width && i<256;i++)
		 	c[i]=a[i]+b[i];
		
	} 
	// Ending of parallel region 
	end = clock();
	/*for(int i=0;i<256;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	
	printf("\n the time taken is:: %f\n",end-start);
} 
