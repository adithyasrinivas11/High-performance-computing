#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXSIZE 1000000

int main(int argc, char **argv)
{
	int myid, numprocs;				// Process ID and Number of Processors	
	double startwtime, endwtime, totalTime; 	// Variable for estimating execution Time
	int namelen;					// Process name length
	long int s, s0, startIndex, endIndex;		// Variables for load sharing purpose
	long int  i;
	float data[MAXSIZE], sum, part_sum;		// Variable for Input Data, Final Sum, and Partial sum.
	char fn[255];
	FILE *fp;

	char processor_name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);				// Tells MPI Number of processors to use from prompt
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs); 	// Get the number of Processors available from MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);		// Get the ID allocated to the current node/processor
	MPI_Get_processor_name(processor_name, &namelen); // Get the current node/processor name and stored into an array of char from MPI

	fprintf(stderr, "Process %d is on %s\n", myid, processor_name);
	fflush(stderr);
	
	// Read Input from file data.txt
	if(0 == myid) {
		/* open input file and intialize data */
		strcpy(fn, getenv("PWD"));
		strcat(fn, "/data.txt");
		if( NULL == (fp = fopen(fn, "r")) ) {
			printf("Can't open the input file: %s\n\n", fn);
			exit(1);
		}
		for(i=0; i<MAXSIZE; i++) {
			fscanf(fp, "%f", &data[i]);
		}
	}
 
	if(myid == 0)
	{
		s = (int) (MAXSIZE/numprocs);	// Total number of elements/numbers for each worker (load of the worker)
		s0 = s + MAXSIZE%numprocs;		// Amount of numbers MASTER will Process
		printf("s=%d, s0=%d\n", s, s0);
	}

	/* broadcast data */
	MPI_Bcast(&s, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);	// Broadcast to ALL from Master's buffer to Worker
	MPI_Bcast(&s0, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	startIndex = s0 + (myid - 1) *s;	// Masters size + (Node# -1) * Worker Size
	endIndex = startIndex + s;		// start + Worker size

	totalTime = 0;		// Initialize Total Execution time to 0
	if (myid == 0)
	{
		startwtime = MPI_Wtime();	// Only MASTER needs to keep track of execution Time
	}
	
	sum = 0;
	part_sum = 0;

	if (myid == 0)			// Master work
	{
		for(i=0; i < s0; i++)	// Compute sum of master's work
		{
			part_sum = part_sum + data[i];
		}
		printf("I got Partial Sum = %f from %d\n", part_sum, myid);
	}
	else						// Workers Work
	{
		for(i=startIndex; i<endIndex; i++)
		{
			part_sum = part_sum + data[i];
		}
		printf("I got Partial Sum = %f from %d\n", part_sum, myid);
	}
	
	/* compute global sum -- Combine local part_sum into the MASTERs buffer sum */
	MPI_Reduce(&part_sum, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);	

	if(myid==0) 
	{
		endwtime = MPI_Wtime();			// Get Current Wall Clock Time
		totalTime = endwtime - startwtime;	// Compute Execution Time

		printf("The Grand sum is %f.\n", sum);			// Print grand Sum
		printf("The Execution Time = %f sec\n",totalTime);	// Print Execution Time
	}

	MPI_Finalize();			// Exit the MPI programming environmemt
}
