#include<stdio.h>
#include<stdlib.h>
#define MAX 15

int top1=-1,top2=MAX+1,stack[MAX+1],i;

void push(int,int);
int pop(int);
void traverse(int);

main()
{
        int data,choice,item,co,st;

        while(1)
        {
                printf("\n\n\tMenu\n1.push\n2.pop\n3.traverse\n4.print top element\n5.number of elements in stack\n6.exit\n");
                printf("\nEnter ur choice and stack no to do operation on(1 0r 2):\t");
                scanf("%d %d",&choice,&st);

                switch(choice)
                {
                        case 1:printf("\nEnter the data to be inserted:\t");
                               scanf("%d",&data);
                               push(data,st);break;
                        case 2:if(st==1)
			       {
					if(top1==-1)
                                        	printf("\nUnderflow\n");
                               		else
                                	{
                                        	item=pop(st);
                                        	printf("\nThe element deleted is\t %d\n",item);
                                	}
				}
				else if(st==2)
				{
					if(top2==MAX+1)
                                                printf("\nUnderflow\n");
                                        else
                                        {
                                                item=pop(st);
                                                printf("\nThe element deleted is\t %d\n",item);
                                        }
				}
                                break;
                        case 3:traverse(st);break;
			case 4:if(st==1)
			       		printf("\nThe top element is :\t%d\n",stack[top1]);
			       else
					printf("\nThe top element is :\t%d\n",stack[top2]);
			       break;
                        case 5:if(st==1)
					printf("\nThe number of elements in stack is:\t%d\n",top1+1);
			       else
					printf("\nThe number of elements in stack is:\t%d\n",MAX-top2+1);
			       break;
                        case 6:exit(0);
                        default:printf("\nInvalid choice\n");
                }
        }
}

void push(int data,int st)
{

	if(st==1)
	{
        	if(top1+1==top2)
                	printf("\nOverflow\n");
        	else
        	{
           		top1++;
			stack[top1]=data;
        	}
	}
	else
	{
		if(top2-1==top1)
			printf("\nOverflow\n");
		else
		{
			top2--;
			stack[top2]=data;
		}
	}
}

int pop(int st)
{

        int item;

	if(st==1)
	{
        	item=stack[top1];
		stack[top1]='\0';
        	top1--;
	}
	else
	{
		item=stack[top2];
		stack[top2]='\0';
		top2++;
	}

        return item;
}

void traverse(int st)
{
	if(st==1)
	{

        	if(top1==-1)
                	printf("\nStack is empty\n");
        	else
        	{
                	printf("\nThe elements in stack are:\t");

                	for(i=top1;i>=0;i--)
                        	printf("%d   ",stack[i]);
                	printf("\n");
        	}
	}
	else if(st==2)
	{
		if(top2==MAX+1)
                        printf("\nStack is empty\n");
                else
                {
                        printf("\nThe elements in stack are:\t");

                        for(i=top2;i<=MAX;i++)
                                printf("%d   ",stack[i]);
                        printf("\n");
                }

	}
}
