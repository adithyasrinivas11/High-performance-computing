#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[100000],b[100000],sum=0;
	for(int i=0;i<100000;i++)
	{	a[i]= pow(2,15)+rand()+0.13246549884;//rand();
		b[i]= pow(2,16)+rand()+0.75245496088;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
	
	
	// Beginning of parallel region 
	double start, end;
  	
	
  	start = omp_get_wtime();
	
	#pragma omp parallel for default(shared) reduction(+: sum)
	for (auto int i = 0; i < 100000; i++)
	{
	    sum += a[i]*b[i];
	    //printf("%lf  \n",sum);
	}
	// Ending of parallel region 
	end = omp_get_wtime();
	/*for(int i=0;i<256;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	
	printf("\n the time taken is:: %f\n",end-start);
} 

