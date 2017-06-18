#include<stdio.h>



void rankf(int n,int s,int a[10],int k);

int n,s,i,j,a[10],b[10],t;

/*struct rank
{
	int n;
	int s;
}r[10];

*/


void main()
{	
	int k=1;
	//printf("enter the t\t");
	//scanf("%d",&t);
	//for(i=1;i<=t;i++)
	//	scanf("%d  %d",&n,&s);


	printf("enter n and s");
	scanf("%d  %d",&n,&s);
	for(j=1;j<=s;j++)
		a[j]=1;

	for(i=1;i<=s;i++)
		b[i]=a[i];
	rankf(n,s,a,k);
	printf("the set is\t");


	
	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
}



void rankf(int n,int s,int a[10],int k)
{
	if(n==s)
		while(k<=s)	
		{
			b[k]=a[k];
			k++;
		}
	else if(n==1)
		b[k]=s;
	else if(n==2)
	{
		b[k]=s/2;
		b[k+1]=s/2+s%2;
	}
	else
	{
		k++;
		b[k]=a[k]+a[k+1];
		rankf(n-2,s-3,a,k+1);
	}
}	
	
