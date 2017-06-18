#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void make_ll();
int pop();
void traverse();
int count();

struct node
{
	int data;
	struct node *link;
}*top=NULL;

main()
{
	struct node *ll;

	make_ll(&ll);
	reverse_ll(&ll);
	traverse(&ll);
	
}

void make_ll(struct node *ll)
{
	do
	{
		int data;
		char ch;
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));

		if(temp==NULL)
			printf("\nMemory insufficient\n");
		else
		{
			printf("\nEnter the element:\t");
			scanf("%d",&data);

			temp->data=data;
	
			if(ll!=NULL)
				temp->link=ll;

			ll=temp;
		}
	printf("\nif u want to add more data enter character 'y':\t");
	scanf("%c",&ch);
	}while(ch=='y');
}

void reverse(struct node *ll)
{
	struct node *ptr1,*ptr2,*temp;

	ptr1=ll->link;
	ptr2=ll;
	temp=ptr1;
	ptr2->link=NULL;
	while(temp!=NULL)
	{
		temp=temp->link;
		ptr1->link=ptr2;
		ptr2=ptr1;
		ptr1=temp;
	}

}

void traverse(struct node *temp)
{

	if(temp==NULL)
		printf("\nlinked list is empty\n");
	else
	{
		printf("\nThe elements in linked list are:\t");

		while(temp!=NULL)
		{
			printf("%d   ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

