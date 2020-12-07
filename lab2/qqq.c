#include <stdio.h>
#include <omp.h> 
int main(int argc, char* argv[]) 
{

int i, p;
int x[5] = {1,1,1,1,1};
int y[5]={0,1,2,3,4};
#pragma omp parallel private (p)
{
p=5;
#pragma omp for
for (i=0; i<5; i++)
{
	x[i]= y[i] * p;
	printf(" %d %d\n",x[i],y[i]);
}

}


return 0;
}
