#include <stdio.h>
#include <mpi.h>
#include<math.h>
int main(int argc, char **argv)
{
  /* double a[1000],b[1000];
   for(int i=0;i<100000;i++)
	{	a[i]= pow(2,15)+rand()+0.13246549884;//rand();
		b[i]= pow(2,16)+rand()+0.75245496088;//rand();
		//printf("%f   %f\n",a[i],b[i]);
	}	
   */
	int node;
	int world_size;
	double t1, t2;
	
	MPI_Init(&argc,&argv);
	t1 = MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &node);

	printf("Hello World from Node %d\n",node);

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if(node == 0)
	{
		double a[1000],b[1000],c[1000];
		 for(int i=0;i<1000;i++)
		{	
			a[i]= i;//pow(2,15)+rand()+0.13246549884;//rand();
			b[i]= i;//pow(2,16)+rand()+0.75245496088;//rand();
			
			//c[i]=a[i]+b[i];
			//printf("%f   %f\n",a[i],b[i]);
		}	
		int load_per_proc;
		if(world_size!=1)
		{
			load_per_proc=1000/(world_size-1);
			
		}
		else 
			load_per_proc=1000;
			
		double c1[load_per_proc];
		//printf("load== %d \n ",load_per_proc);
		MPI_Status status;

		if(world_size>1)
		{
			for(int i=1;i<world_size;i++)
			{	MPI_Send(&load_per_proc,1,MPI_INT,i,1,MPI_COMM_WORLD);
			
				MPI_Send(&a,1000,MPI_DOUBLE,i,0,MPI_COMM_WORLD);
		
				MPI_Send(&b,1000,MPI_DOUBLE,i,0,MPI_COMM_WORLD);
			}
			// for(int i=500;i<1000;i++)
			//	c[i]=a[i]+b[i];
			
			int n1;
			for(int i1=1;i1<world_size;i1++)
			{
				MPI_Recv(&c1,load_per_proc,MPI_DOUBLE,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,&status);
				MPI_Recv(&n1,1,MPI_DOUBLE,MPI_ANY_SOURCE,2,MPI_COMM_WORLD,&status);
				
				for(int i=(n1-1)*load_per_proc;i<(n1)*load_per_proc;i++)
					c[i]=c1[i];
			}  
			
			
		} 
		else
		{
			//printf("line no 69");
			for(int i=0;i<1000;i++)
				c[i]=a[i]*b[i];
		
		}
		for(int i=0;i<1000;i++)
			   	printf("%f \n ",c[i]);
		
	}
	else
	{
	  	printf(" in here drom %d \n ",node);
		double a[1000],b[1000];
		MPI_Status status;
		int load_per_proc;
		MPI_Recv(&load_per_proc,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);		//receiving load/process
		
		MPI_Recv(&a,1000,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);		//receiving a

		MPI_Recv(&b,1000,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);		//receiving b
		
		double c[load_per_proc];
		
		for(int i=(node-1)*load_per_proc;i<node*load_per_proc;i++)
			c[i]=a[i]*b[i];

		MPI_Send(&c,load_per_proc,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
		MPI_Send(&node,1,MPI_INT,0,2,MPI_COMM_WORLD);

		//   	    	   	printf("%f   %f  %d\n ",c[i]);

			
	}  
	 t2 = MPI_Wtime();
	MPI_Finalize();
	 
	 printf("%f",t2-t1);
return 0;
}
