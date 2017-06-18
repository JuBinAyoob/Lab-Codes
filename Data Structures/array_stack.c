#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top=-1,stack[MAX],i;
void push(int);
int pop();
void traverse();
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
                        case 2:if(top==-1)
                                        printf("\nUnderflow\n");
                               else
                                {
                                        item=pop();
                                        printf("\nThe element deleted is\t %d\n",item);
                                }
                                break;
                        case 3:traverse();break;
			case 4:printf("\nThe top element is :\t%d\n",stack[top]);break;
                        case 5:printf("\nThe number of elements in stack is:\t%d\n",top+1);break;
                        case 6:exit(0);
                        default:printf("\nInvalid choice\n");
                }
        }
}

void push(int data)
{

        if(top==MAX)
                printf("\nOverflow:wq\n");
        else
        {
           	top++;
		stack[top]=data;
        }
}

int pop()
{
        int item;

        item=stack[top];
	stack[top]='\0';
        top--;

        return item;
}

void traverse()
{

        if(top==-1)
                printf("\nStack is empty\n");
        else
        {
                printf("\nThe elements in stack are:\t");

                for(i=top;i>=0;i--)
                        printf("%d   ",stack[i]);
                printf("\n");
        }
}
                                             
