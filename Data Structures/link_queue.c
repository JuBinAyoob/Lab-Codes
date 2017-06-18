#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*front=NULL,*rear=NULL;

void enqueue(int);
int dequeue();
void traverse();

main()
{
        int choice,item,data;

        while(1)
        {
                printf("\n\n\tMenu\n1.ENQUEUE operation\n2.DEQUEUE operation\n3.traverse\n4.exit\n");
                printf("\nEnter ur choice:\t");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:printf("\nEnter the data to be inserted:\t");
                               scanf("%d",&data);
			       enqueue(data);break;
                        case 2:if(front==NULL)
                                        printf("\nUnderflow\n");
                               else
                                {
                                        item=dequeue();
                                        printf("\nThe element deleted is\t %d\n",item);
                                }
                                break;
                        case 3:traverse();break;
			//case 4:printf("\nThe front element is :\t%d\n",stack[top]);break;
                        //case 5:printf("\nThe number of elements in stack is:\t%d\n",top+1);break;
                        case 4:exit(0);
                        default:printf("\nInvalid choice\n");
                }
        }
}

void enqueue(int data)
{

	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));

        if(new==NULL)
                printf("\nMemory insufficient\n");
        else
        {
		new->data=data;
		new->link=NULL;

		if(front==NULL)
		{
			front=new;
			rear=new;
		}
		else
		{
           		rear->link=new;
			rear=new;
		}
        }
}

int dequeue()
{
        int item;
	struct node *del;

	del=front;
        item=front->data;

	if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
        	front=front->link;

	free(del);
        return item;
}

void traverse()
{

	struct node *traverse;
        
	if(front==NULL)
                printf("\nQueue is empty\n");
        else
        {
                printf("\nThe elements in queue are:\t");

                for(traverse=front;traverse!=NULL;traverse=traverse->link)
                        printf("%d   ",traverse->data);
	printf("\n");
        }
}
