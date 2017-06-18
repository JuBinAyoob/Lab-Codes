#include<stdio.h>

int i,j,temp;

void read(int [],int);
void quick_sort(int [],int,int);
int partition(int [],int,int);
void display(int [],int);

main()
{
        int a[50],n;
	
	printf("\nEnter the size to array(max 50):\t");
       	scanf("%d",&n);


	read(a,n);
	quick_sort(a,0,n-1);
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
            

void quick_sort(int a[],int low,int high)
{
	int pivot;
			
	if(low<high)
	{
		pivot=partition(a,low,high);
		quick_sort(a,low,pivot-1);
		quick_sort(a,pivot+1,high);
	}
}

int partition(int a[],int low,int high)   
{
	int left,right,pivot_item;

	pivot_item=a[low];

	left=low;
	right=high;
	while(left<right)
	{
		while(a[left]=>pivot_item)
			left++;
		while(a[right]<pivot_item)
			right--;

		if(left<right)
        	{
                	temp=a[left];
                	a[left]=a[right];
                	a[right]=temp;
        	}
	}

	temp=a[low];
	a[low]=a[right];
	a[right]=temp;

	return right;

}


