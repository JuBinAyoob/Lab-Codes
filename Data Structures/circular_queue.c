#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int front=-1,rear=-1,queue[MAX],i;

void enqueue();
int dequeue();
void traverse();

main()
{
        int choice,item;

        while(1)
        {
                printf("\n\n\tMenu\n1.ENQUEUE operation\n2.DEQUEUE operation\n3.traverse\n4.exit\n");
                printf("\nEnter ur choice:\t");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:enqueue();break;
                        case 2:if(front==-1)
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

void enqueue()
{
	int data;

        if(front==(rear+1)%MAX)
                printf("\nOverflow\n");
        else
        {
		printf("\nEnter the data to be inserted:\t");
        	scanf("%d",&data);

		if(front==-1)
			front=0;
           	rear=(rear+1)%MAX;
		queue[rear]=data;
        }
}

int dequeue()
{
        int item;

        item=queue[front];
	queue[front]='\0';

	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
        	front=(front+1)%MAX;

        return item;
}

void traverse()
{

        if(front==-1)
                printf("\nQueue is empty\n");
        else
        {
                printf("\nThe elements in queue are:\t");

                for(i=front;i!=rear;i=(i+1)%MAX)
                        printf("%d   ",queue[i]);
                printf("%d\n",queue[rear]);
        }
}
