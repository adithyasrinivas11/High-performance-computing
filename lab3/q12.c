#include <omp.h> 
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
int main(int argc, char* argv[]) 
{ 
	srand(time(NULL));
	double a[1000000],sum=0;
	for(int i=0;i<1000000;i++)
	{	a[i]= pow(2,15)+rand()+0.13246549884;//rand();
		//b[i]= i;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
	
	
	// Beginning of parallel region 
	double start, end;
  	
	sum = 0;
  	start = omp_get_wtime();
		   // double s=0;
	#pragma omp parallel
	{
	double s=0;
	#pragma omp parallel for 
	for (auto int i = 0; i < 1000000; i++)
	{

	    s += a[i];
	    //printf("%lf  \n",sum);
	}
	#pragma omp critical
		sum+=s;
	}// Ending of parallel region 
	end = omp_get_wtime();
	/*for(int i=0;i<256;i++)
	{
		printf("%f   %f   %f\n",a[i],b[i],c[i]);
	}*/
	
	printf("\n the time taken is:: %f\n",end-start);
} 

