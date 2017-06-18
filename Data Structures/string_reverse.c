#include<stdio.h>
#include<string.h>
#define MAX 50

int top=-1,i;
char stack[MAX];

void reverse_string(char []);
void push(char);
int pop();

main()
{
	char strg[MAX];

	printf("\nEnter a string(max size 50):\t");
	gets(strg);

	reverse_string(strg);

	printf("\nThe reversed string is:\t");
	puts(strg);
	printf("\n");
}

void reverse_string(char strg[])
{
	int i=0;

	while(strg[i]!='\0')
		push(strg[i++]);
	
	i=0;
	while(top!=-1)
		strg[i++]=pop();
			
}

void push(char data)
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
