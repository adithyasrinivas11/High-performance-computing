#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<string.h>
#define num_of_elements 22269
#define num_of_centroids 4
int k=4;
int points_x[num_of_elements];
int points_y[num_of_elements];
int points_closest[num_of_elements];
int centroids_x[num_of_elements]; 
int centroids_y[num_of_elements];
int centroids_closest[num_of_elements];  

void assign_centroids(); 
void assignment();
void cluster_update();
void gnu_draw();

const char* read_values(char* line, int num)
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

int main(){
	
    int i=0;
    //Reading data from the csv file
    FILE* stream = fopen("data_pcap.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        points_x[i]=atoi(read_values(tmp,1));
        printf("\n%d",points_x[i]);
        i++;
        //free(tmp);
    }
    
    FILE* stream1 = fopen("data_pcap.csv", "r");
    i=0;
    char line1[1024];
    while (fgets(line1, 1024, stream1))
    {
        char* tmp = strdup(line1);
        points_y[i]=atoi(read_values(tmp,2));
        printf("\n  %d ",points_y[i]);
        //printf("\n%d",i);
        i++;
        free(tmp);
    }
    

    while(i<num_of_elements) 
    {

        points_closest[i] = 0;
        i++;
    }

    
    assign_centroids();// To randomly choose the centroids 
    
    for(int i=0;i<num_of_centroids;i++)
       printf("\n%d %d",centroids_x[i],centroids_y[i]);

    assignment(); // assign the points the cluster number close to the centroids
    cluster_update();//update the centroids

    assignment();// assign the points the cluster number close to the centroids

        
    int num=1;
    int iteration=0;
    while(num)
    {
    	int centroid_check_x[num_of_elements];
    	int centroid_check_y[num_of_elements];
    	int centroid_check_closest[num_of_elements];
    	for(int i=0;i<num_of_elements;i++)
    	{
    		centroid_check_x[i]=points_x[i];
    		centroid_check_y[i]=points_y[i];
    		centroid_check_closest[i]=points_closest[i];
    	}
        cluster_update();
        
        assignment();
        num=0;
        for(int i=0;i<num_of_elements;i++)
        {
            if(points_closest[i]!=centroid_check_closest[i])
            {
                num=1;
            }
        } 
    }
    
    printf("Drawing the chart...\n");
    gnu_draw();
    
    for(int i=0;i<num_of_centroids;i++)
       printf("\n%d %d",centroids_x[i],centroids_y[i]);

    //drawpoint();
    return 0;
}

void assign_centroids()
{
    int x_coor,y_coor;
    srand(time(0)); 
    for(int i=0;i<k;i++)
    {
        x_coor=points_x[rand()%22269];
        y_coor=points_y[rand()%22269];
        centroids_x[i]=x_coor;
        centroids_y[i]=y_coor;
    }   
}

void assignment()
{
    int distance[num_of_elements][num_of_centroids];
    int j;
   for(int i=0;i<num_of_elements;i++)
    {
        int min=999;
        for( j=0;j<num_of_centroids;j++)
        {
             distance[i][j]=sqrt(pow((points_x[i] - centroids_x[j]),2)+pow((points_y[i] - centroids_y[j]),2));
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
    //cout<<"\nUpdated centroids";
    for(int i=0;i<num_of_centroids;i++)
    {
        int sum_x=0,sum_y=0;
        int num1=0,num2=0;
        for(int j=0;j<num_of_elements;j++)
	    {
	           
	            if(points_closest[j]==i)
	            {
	                sum_x=sum_x+points_x[j];
	                
	            }

	    } 
        for(int l=0;l<num_of_elements;l++)
        {
            if(points_closest[l]==i)
            {
                num1=num1+1;
            }
            
        }
        for(int j=0;j<num_of_elements;j++)
        {
               
                if(points_closest[j]==i)
                {
                    sum_y=sum_y+points_y[j];
                    
                }

        }
    	for(int l=0;l<num_of_elements;l++)
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
    for(int i = 0; i < num_of_elements; i++)
    {
        fprintf(fp, "%d %d %d \n",points_x[i],points_y[i],points_closest[i]);
    }
    fclose(fp);
    

    system("gnuplot -p -e \" plot 'data.txt' using 1:2:3 with points palette notitle  \"");
    remove("data.txt");

}
