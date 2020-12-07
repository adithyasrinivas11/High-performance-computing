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
   double t1, t2;
    t1 = MPI_Wtime();
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &node);
     
   printf("Hello World from Node %d\n",node);
   
   
   if(node == 0)
   {
   	double a[1000],b[1000],c[1000];
  	 for(int i=0;i<1000;i++)
	{	
		a[i]= i;//pow(2,15)+rand()+0.13246549884;//rand();
		b[i]= i;//pow(2,16)+rand()+0.75245496088;//rand();
		
		c[i]=a[i]+b[i];
		//printf("%f   %f\n",a[i],b[i]);
	}	
   	
   	subset=1000/
   	MPI_Status status;
   	
   	MPI_Send(&a,500,MPI_DOUBLE,1,0,MPI_COMM_WORLD);
   	
   	MPI_Send(&b,500,MPI_DOUBLE,1,0,MPI_COMM_WORLD);
   	
   	 for(int i=500;i<1000;i++)
   	 	c[i]=a[i]+b[i];
   
   	  MPI_Recv(&c,500,MPI_DOUBLE,1,0,MPI_COMM_WORLD,&status);
   	  
    //for(int i=0;i<1000;i++)
    	//   	printf("%f \n ",c[i]);
   } 
   
   else
   {
   	double a[1000],b[1000],c[500];
   	MPI_Status status;
   	MPI_Recv(&a,500,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);
   	
   	MPI_Recv(&b,500,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);
   	
   	for(int i=0;i<500;i++)
   		c[i]=a[i]+b[i];
   	
   	MPI_Send(&c,500,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
   	
//   	    	   	printf("%f   %f  %d\n ",c[i]);

   		
   }  
   
   MPI_Finalize();
	  t2 = MPI_Wtime();
	 printf("%f",t2-t1);
return 0;
}
