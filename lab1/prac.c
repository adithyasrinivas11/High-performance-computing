
#include <stdio.h> 
 

int main(int argc, char* argv[]) 
{ 
	float x,p,tp,t1,zz; // p no od threads x is 
	t1=0.003778;
	tp=0.002084;
	p=24;
	float z=t1-tp;
	z=z/t1;
	zz=p/(p-1);
	
	float ans=z*zz;
	printf("\n the time taken is:: %f\n",ans);
} 

