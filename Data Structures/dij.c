#include<stdio.h>

int n,parent[10],priority[10],check[10],d[10],g[10][10],s,u,v;

int extractmin();
void relax(int u,int v);

main()
{
	int i,j,k=0;

	printf("\nenter the number of vertice:\t");
	scanf("%d",&n);

	printf("\nenter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);

	while(1)
	{
		printf("\nenter source node:\t");
		scanf("%d",&s);

		for(j=0;j<n;j++)
		{
			parent[j]=-1;
			priority[j]=9999;
			check[j]=0;
			d[j]=9999;
		}

		priority[s]=0;
		d[s]=0;

		while((u=extractmin())!=-1)
			for(v=0;v<n;v++)
				if(g[u][v]!=0)
					relax(u,v);

		printf("node        path from node %d        distance\n",s);
		printf("----        -----------------        -------\n");
	
		for(i=0;i<n;i++)
		{
			printf("%4d",i);
			j=i;
			printf("%9d",j);
		
			k=0;
	
			while(parent[j]!=-1)
			{
				printf("--%d",parent[j]);
				j=parent[j];
				k++;
			}
			switch(k)
			{
				case 0:printf("%27d   \n",d[i]);break;
				case 1:printf("%24d   \n",d[i]);break;
				case 2:printf("%21d   \n",d[i]);break;
				case 3:printf("%18d   \n",d[i]);break;
				case 4:printf("%15d   \n",d[i]);break;
				default:printf("%12d   \n",d[i]);
			}
		}
	}
}

int extractmin()
{
	int p=-1,u=9999,i;

	for(i=0;i<n;i++)
		if(check[i]==0&&priority[i]<u)
		{
			u=priority[i];
			p=i;
		}	

	if(p!=-1)
		check[p]=1;

	return p;
}

void relax(int u,int v)
{
	if(d[v]>(d[u]+g[u][v]))
	{
		d[v]=d[u]+g[u][v];
		parent[v]=u;
		priority[v]=d[v];
	}
}


