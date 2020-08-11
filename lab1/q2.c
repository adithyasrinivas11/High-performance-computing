#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[100000],b[100000], c[100000];
	for(int i=0;i<100000;i++)
	{	a[i]= pow(2,15)+rand()+0.132465498;//rand();
		b[i]= pow(2,13)+rand()+0.1684321846;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
	
	
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

		for(int i=0;i<100000;i=i++)
		 	c[i]=a[i]+b[i];
	} 
	// Ending of parallel region 
	end = omp_get_wtime();
	/*for(int i=0;i<256;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	
	printf("\n the time taken is:: %f\n",end-start);
} 

