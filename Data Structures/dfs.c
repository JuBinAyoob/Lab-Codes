#include<stdio.h>

int i,num[10]={0};

DFS_VISIT(int G[10][10],int n,int v)
{
 	int w;
 	//i++;
 	num[v]=1;
 	for(w=0;w<n;w++)
	{
 		if(G[v][w]!=0&&num[w]==0)
		{
 			printf("%d",w);
 			DFS_VISIT(G,n,w);
		}
	}
}

DFS(int G[10][10],int n)
{
	int x,y;
 	
	for(x=0;x<n;x++)
	{
 		for(y=0;y<n;y++)
 			num[y]=0;

 		//i=0;
 		
		if(num[x]==0)
		{
 			printf("\n%d",x);
 			DFS_VISIT(G,n,x);
		}
	
 		printf("\n");
	}
}

main()
{
 	int G[10][10],n,i,j,k,ele;
 	
	printf("\nNumber of vertices in the graph\n");
 	scanf("%d",&n);
 	
	printf("\nadjacency matrix of graph \n");
 	for(i=0;i<n;i++)
 		for(j=0;j<n;j++)
 			scanf("%d",&G[i][j]);
 	j=0;

 	DFS(G,n);
}

