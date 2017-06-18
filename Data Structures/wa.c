#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int w[MAX][MAX],d[MAX][MAX][MAX],p[MAX][MAX][MAX];

int min(int,int);
void floyd(int);

main()
{
	int i,j,k,v; 
	
	printf("\nenter the number of vertices:\t");
	scanf("%d",&v);

	printf("\nenter the adjacency matrix:\n");
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			scanf("%d",&w[i][j]);

	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			if((i==j)||(w[i][j]==9999))
				p[0][i][j]=-1;
			else
				p[0][i][j]=i;

	floyd(v);
}

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;

}

void floyd(int v)
{
	int i,j,k=0,path[10],source,dest,f=1;
	
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


	printf("\n*******Final cost or distance matrix*******\n\n");
	

	for(i=1;i<=v;i++)
	{

		for(j=1;j<=v;j++)	
			if(d[v][i][j]<=9900)
				printf("\t%d",d[v][i][j]);
			else
				printf("\tinfinity");
		printf("\n\n");
	}

	printf("\nthe path matrix is\n\n");

		
	for(i=1;i<=v;i++)
	{

		for(j=1;j<=v;j++)
			if(p[v][i][j]<=9900)
				printf("\t%d",p[v][i][j]);
			else
				printf("\tinfinity");
		printf("\n\n");
	}

	while(1)
	{
		i=-1;
		f=1;

		printf("\nenter the source node(-1 == stop):\t");
		scanf("%d",&source);

		if(source==-1)
			exit(0);

		printf("\nenter the destination node:\t");
		scanf("%d",&dest);

		j=dest;
		path[++i]=dest;

		while(p[v][source][j]!=source)
			if(p[v][source][j]==-1)
			{
				printf("\nno path\n");
				f=0;
				break;
			}
			else
			{	
				path[++i]=p[v][source][j];
	
				if(p[v][source][path[i]]==source)
				{
					path[++i]=source;
					break;
				}

				j=path[i];
			}

		if(f)
		{
			//path[++i]=source;
			printf("\nPATH:\t");
				
			if(path[i]!=source)
				path[++i]=source;
				
			while(i>0)
				printf("%d-->",path[i--]);

			printf("%d\n",path[i--]);
		}
	}	
}
