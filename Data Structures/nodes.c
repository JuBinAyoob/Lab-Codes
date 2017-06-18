#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void push(int);
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
	int data,choice,item,co,n;

	while(1)
	{
		printf("\nhow many nodes you want to creat(nth node):\t");
		scanf("%d");
	}
}

void push(int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));

	if(temp==NULL)
		printf("\nMemory insufficient\n");
	else
	{
		temp->data=data;
	
		if(top!=NULL)
			temp->link=top;

		top=temp;
	}
}

int pop()
{
	struct node *temp;
	int item;

	temp=top;

	item=temp->data;
	top=top->link;
	free(temp);

	return item;
}

void traverse()
{
	struct node *temp;

	temp=top;

	if(temp==NULL)
		printf("\nStack is empty\n");
	else
	{
		printf("\nThe elements in stack are:\t");

		while(temp!=NULL)
		{
			printf("%d   ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int count()
{
	struct node *temp;

        temp=top;

	int co=0;
	for(;temp!=NULL;temp=temp->link)
		co++;

	return co;
}

