#include<stdio.h>
#include<stdlib.h>
#define max 10

int w[max][max],d[max][max][max],p[max][max][max];

void floyd(int);
int min(int,int);

int min(int a,int b)
{
	if(a<=b)
 		return a;
	else
 		return b;
}

main()
{
	int v,i,j,k;

	printf("enter the no:of vertices\n");
	scanf("%d",&v);

	printf("enter the adjacency matrix\n");
	
	for(i=1;i<=v;i++)
 		for(j=1;j<=v;j++)
   			scanf("%d\n",&w[i][j]);

	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
  			if(i==j||(w[i][j]==9999))
      				p[0][i][j]=-1;
  			else
    				p[0][i][j]=i;
 		
	floyd(v);
}

void floyd(int v)
{

	int i,j,k,path[10],s,de,f=1;
	k=0;

	for(i=1;i<=v;i++)
  		for(j=1;j<=v;j++)
    			d[k][i][j]=w[i][j];
	
	for(k=1;k<=v;k++)
 		for(i=1;i<=v;i++)
  			for(j=1;j<=v;j++) 
   			{
    				d[k][i][j]=min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
    
				if(d[k][i][j]==d[k-1][i][j])
      					p[k][i][j]=p[k-1][i][j];
    				else
      					p[k][i][j]=p[k-1][k][j];
   			}

	//for(k=0;k<=v;i++)
	printf("\n*****final cost or distance matrix****\n\n");

	printf("k=%d\n",k);
 	for(i=1;i<=v;i++)
 	{
		for(j=1;j<=v;j++)
   			if(d[v][i][j]<=9900)
     				printf("\t%8d",d[v][i][j]);
   			else
     				printf("\tinfinity\n");
  		printf("\n\n");
 	}


	printf("\n****path matrix******\n");

	for(i=1;i<=v;i++)
	{
  		printf("\n");
 		for(j=1;j<=v;j++)
 			if(d[v][i][j]<=9900)
  				printf("\t%8d",p[v][i][j]);
  			else
   				printf("\tinfinity");
  	}
   
	while(1)
	{
 	
		i=-1;
 		f=1;

		printf("enter the sourceand destination nodes to find path(enter source=-1 to stop)node starts from 1\n");
		scanf("%d%d",&s,&de);

		j=de;
		path[++i]=de;

		while(p[v][s][j]!=s)
 		{
  			if(p[v][s][j]==-1)
   			{
    				printf("no path\n");
    				f=0;
    				break;
			}
  			else
   			{
    				path[++i]=p[v][s][j];
     
				if(p[v][s][path[i]]==s)
      				{
        				path[++i]=s;
        				break;
      				}
     
				j=path[i];
   			}
 		}

		if(f)
  		{
    			printf("path:\t");
    
			if(path[i]!=s)     
       				path[++i]=s;
       
			while(i>0)
          			printf("%d-->",path[i--]);
        
			printf("%d",path[i--]);
     		}
  	}
}
