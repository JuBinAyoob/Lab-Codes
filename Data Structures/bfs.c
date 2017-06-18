#include<stdio.h>

int g[10][10],visit[10]={0},q[10]={0},n,front=-1,rear=-1;

int main()
{
	int i,j,ele,k;
	
	printf("\nEnter the number of vertices:\t");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);

	for(j=0;j<n;j++)
	{
		for(k=0;k<n;k++)
			visit[k]=0;

		printf("\nstarting node:%d\n",j);
		printf("nodes reachable from %d:   ",j);
		
		front=-1;
		rear=-1;
		visit[j]=1;
		q[++rear]=j;

		while(front!=rear)
		{
			ele=q[++front];
			printf("%d  ",ele);
			for(i=0;i<n;i++)
			{
				if(visit[i]==0&&g[ele][i]!=0)
				{
					visit[i]=1;
					q[++rear]=i;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

