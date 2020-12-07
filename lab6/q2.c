#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include<math.h>

const int m=5;
int main(int argc, char **argv)
{
  /* double a[1000],b[1000];
   for(int i=0;i<100000;i++)
        {       a[i]= pow(2,15)+rand()+0.13246549884;//rand();
                b[i]= pow(2,16)+rand()+0.75245496088;//rand();
                //printf("%f   %f\n",a[i],b[i]);
        }
   */
        int node;
        int world_size;
        double t1, t2;
        srand(time(NULL));
        MPI_Init(&argc,&argv);
        t1 = MPI_Wtime();
        MPI_Comm_rank(MPI_COMM_WORLD, &node);

        //printf("Hello World from Node %d\n",node);
	double sum=0,sum1=0;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        if(node == 0)
        {
                double a[m],b[m],c[m];
                 for(int i=0;i<m;i++)
                {
                        a[i]= i;//pow(2,15)+rand()+0.13246549884;//rand();
                        b[i]= i;//pow(2,16)+rand()+0.75245496088;//rand();

                        //c[i]=a[i]+b[i];
                        //printf("%f   %f\n",a[i],b[i]);
                }
                int load_per_proc;
			
                if(world_size!=1)
                        load_per_proc=m/(world_size-1);
                else
                        load_per_proc=m;

                double c1[load_per_proc];
                //printf("load== %d \n ",load_per_proc);
                MPI_Status status;

                if(world_size>1)
                {
                        for(int i=1;i<world_size;i++)
                        {       MPI_Send(&load_per_proc,1,MPI_INT,i,1,MPI_COMM_WORLD);

                                MPI_Send(&a,m,MPI_DOUBLE,i,0,MPI_COMM_WORLD);

                                MPI_Send(&b,m,MPI_DOUBLE,i,0,MPI_COMM_WORLD);
                        }
                        int n1,remi,j;
                        for(int i1=1;i1<world_size;i1++)
                        {
                                 MPI_Recv(&n1,1,MPI_INT,MPI_ANY_SOURCE,2,MPI_COMM_WORLD,&status);
                                MPI_Recv(&sum1,1,MPI_DOUBLE,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,&status);
                               
                                sum+=sum1;
                        }
                        int rem = (world_size-1)*load_per_proc;
                        for(int ii= rem;ii<m;ii++)
                        {
                             sum+=a[ii]*b[ii];
                        }

                }
                else
                {
                        //printf("line no 69");
                        for(int i=0;i<m;i++)
                                sum+=a[i]*b[i];

                }
                 
                //for(int i=0;i<m;i++)
                     printf("sum = %f \n ",sum);

        }
        else            //worker nodes
        {
                //printf(" in here drom %d \n ",node);
		double a[m],b[m];
		MPI_Status status;
		int load_per_proc;
		MPI_Recv(&load_per_proc,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);          //receiving load/process

		MPI_Recv(&a,m,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);              //receiving a

		MPI_Recv(&b,m,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);              //receiving b

		double isum=0,c[load_per_proc];
		int j,rem;
		



		for(int i=(node-1)*load_per_proc;i<node*load_per_proc;i++)
			isum+=a[i]*b[i];
		printf("isum = %f\n",isum);
		
		MPI_Send(&node,1,MPI_INT,0,2,MPI_COMM_WORLD);
		MPI_Send(&isum,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);

        }
         t2 = MPI_Wtime();
        if(node == 0)
                 printf(" time taken :: %f \n",t2-t1);
	MPI_Barrier(MPI_COMM_WORLD);
        MPI_Finalize();

        // printf(" time taken :: %f",t2-t1);
return 0;
}
