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
	int data,choice,item,co;

	while(1)
	{
		printf("\n\n\tMenu\n1.push\n2.pop\n3.traverse\n4.print top element\n5.number of elements in stack\n6.exit\n");
		printf("\nEnter ur choice:\t");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("\nEnter the data to be inserted:\t");
			       scanf("%d",&data);
			       push(data);break;
			case 2:if(top==NULL)
					printf("\nThe stack is empty\n");
			       else
				{
					item=pop();
			       		printf("\nThe element deleted is\t %d\n",item);
				}
				break;
			case 3:traverse();break;
			case 4:printf("\nThe top element is :\t%d\n",top->data);break;
			case 5:co=count();
			       printf("\nThe number of elements in stack is:\t%d\n",co);break;
			case 6:exit(0);
			default:printf("\nInvalid choice\n");
		}
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
