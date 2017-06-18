#include<stdio.h>
#define MAX 50

int i,j;

void read(int [],int);
void merge_sort(int [],int,int);
void merge(int [],int,int,int);
void display(int [],int);

main()
{
        int a[MAX],n;
	
	printf("\nEnter the size to array(max 50):\t");
       	scanf("%d",&n);


	read(a,n);
	merge_sort(a,0,n-1);
	display(a,n);
}

void read(int a[],int n)
{

  	printf("\nenter %d elements to array\t",n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}


void display(int a[],int n)
{

        printf("\nThe elements in sorted array are:\t");

        for(i=0;i<n;i++)
          	printf("%d   ",a[i]);
       	printf("\n");
       
}
            

void merge_sort(int a[],int low,int high)
{
	int mid;
			
	if(low!=high)
	{
		mid=(low+high)/2;

		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void merge(int a[],int low,int mid,int high)   
{
	int temp[MAX],i=low,j=mid+1,k=low;

	while(i<=mid && j<=high)
		if(a[i]<=a[j])
                	temp[k++]=a[i++];
		else
                	temp[k++]=a[j++];
                	
	while(i<=mid)
      		temp[k++]=a[i++];
       	while(j<=high)
              	temp[k++]=a[j++];

	for(i=low;i<=high;i++)
		a[i]=temp[i];
		
}


