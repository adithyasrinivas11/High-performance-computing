#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<string.h>

#define N 22269
#define num_of_centroids 4
int k=4;
int datax[N];
int datay[N];
int points_closest[N];
int centroids_x[N]; 
int centroids_y[N];
int centroids_closest[N];  

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
} 


void assign_centroids()
{
    int x,y;
    srand(time(0)); 
    for(int i=0;i<k;i++)
    {
        x=datax[rand()%22000];
        y=datay[rand()%22200];
        centroids_x[i]=x;
        centroids_y[i]=y;
    }   
}

void assignment()
{
    int distance[N][num_of_centroids];
    int j;
   for(int i=0;i<N;i++)
    {
        int min=999;
        for( j=0;j<num_of_centroids;j++)
        {
             distance[i][j]=sqrt(pow((datax[i] - centroids_x[j]),2)+pow((datay[i] - centroids_y[j]),2));
            if(distance[i][j]<min)
            {
                   min=distance[i][j];
                   points_closest[i]=j;
            }
            
        }
    }       
    
}

void cluster_update()
{

    for(int i=0;i<num_of_centroids;i++)
    {
        int sum_x=0,sum_y=0;
        int num1=0,num2=0;
        for(int j=0;j<N;j++)
	    {
	           
	            if(points_closest[j]==i)
	            {
	                sum_x=sum_x+datax[j];
	                
	            }

	    } 
        for(int l=0;l<N;l++)
        {
            if(points_closest[l]==i)
            {
                num1=num1+1;
            }
            
        }
        for(int j=0;j<N;j++)
        {
               
                if(points_closest[j]==i)
                {
                    sum_y=sum_y+datay[j];
                    
                }

        }
    	for(int l=0;l<N;l++)
        {
           if(points_closest[l]==i)
            {
                num2=num2+1;
            }
        }
	    if(num1!=0)
	    {
	    	centroids_x[i]=sum_x/num1;            
	    }
        if(num2!=0)
        {
            centroids_y[i]=sum_y/num2;
            
        }
		       
	}    

}

void gnu_draw()
{

    FILE *fp;

    fp = fopen("data.txt", "w+");
    for(int i = 0; i < N; i++)
    {
        fprintf(fp, "%d %d %d \n",datax[i],datay[i],points_closest[i]);
    }
    fclose(fp);
    

    system("gnuplot -p -e \" plot 'data.txt' using 1:2:3 with points palette notitle  \"");
    remove("data.txt");

}

int main(){
	
    int i=0;
    int dummy_x_points[20200];
    int dummy_y_points[20200];

    FILE* stream = fopen("data_pcap.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        dummy_x_points[i]=atoi(getfield(tmp,4));
        i++;
        
        free(tmp);
    }
    for(int m=1;m<N+1;m++)
    {
        datax[m-1]=dummy_x_points[m];
    }
    FILE* stream1 = fopen("data_pcap.csv", "r");
    i=0;
    char line1[1024];
    while (fgets(line1, 1024, stream1))
    {
        char* tmp = strdup(line1);
        dummy_y_points[i]=atoi(getfield(tmp,5));
        i++;
        free(tmp);
    }
    for(int m=1;m<N+1;m++)
    {
        datay[m-1]=dummy_y_points[m];
    }
    

    while(i<N) 
    {

        points_closest[i] = 0;
        i++;
    }

    
    assign_centroids();
   
    assignment(); 
    cluster_update();
    assignment();

        
    int num=1;
    int iteration=0;
    while(num)
    {
    	int centroid_check_x[N];
    	int centroid_check_y[N];
    	int centroid_check_closest[N];
    	for(int i=0;i<N;i++)
    	{
    		centroid_check_x[i]=datax[i];
    		centroid_check_y[i]=datay[i];
    		centroid_check_closest[i]=points_closest[i];
    	}
        cluster_update();
        
        assignment();
        num=0;
        for(int i=0;i<N;i++)
        {
            if(points_closest[i]!=centroid_check_closest[i])
            {
                num=1;
            }
        } 
    }
    
    printf("Drawing the chart...\n");
    gnu_draw();
    
    //drawpoint();
    return 0;
}

