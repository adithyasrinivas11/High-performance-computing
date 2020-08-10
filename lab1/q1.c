#include <omp.h> 

#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) 
{ 

	// Beginning of parallel region 
	#pragma omp parallel 
	{ 

		int num=omp_get_thread_num();
		printf("Hello World... from thread = %d\n", num+1); 
	} 
	// Ending of parallel region 
} 

