#include<stdio.h>
#include<stdlib.h>

int i,j,temp;

void read(int [],int);
void sort(int [],int);
void display(int [],int);
int binary_search(int[],int,int,int);

main()
{
        int a[50],n,pos,s;
	

	
		printf("\nEnter the size to array(max 50):\t");
       		scanf("%d",&n);


		read(a,n);
		sort(a,n);
		display(a,n);
	while(1)
	{

		printf("\nEnter the element to be searched:\t");
        	scanf("%d",&s);


		pos=binary_search(a,0,n-1,s);

		if(pos==-1)
			printf("\nelement not found\n");
		else
			printf("\nelement fount at position:\t%d\n",pos+1);
               
	}        
}

void read(int a[],int n)
{

  	printf("\nenter %d elements to array\t",n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

		for(j=0;a[j]!=a[i] && j<i;j++);

		if(j!=i)
			i--;
			
	}
       
}


void display(int a[],int n)
{

        printf("\nThe elements in array are:\t");

        for(i=0;i<n;i++)
          	printf("%d   ",a[i]);
       	printf("\n");
       
}
            

void sort(int a[],int n)
{
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}

int binary_search(int a[],int low,int high,int s)   
{
	int mid;

	mid=(low+high)/2;

	if(low<=high)
	{
		if(a[mid]==s)
			return mid;
		else if(a[mid]<s)
                	return binary_search(a,mid+1,high,s);
        	else
                	return binary_search(a,low,mid-1,s);
        }
        return -1;
}
