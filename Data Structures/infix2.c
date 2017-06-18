#include<stdio.h>
#include<ctype.h>
#include<malloc.h>

struct NODE
{
	char data;
	struct NODE *lchild;
	struct NODE *rchild;
};

typedef struct NODE *node;

node exptree(char[]);
void push_cha(node);
void push_op(char);
node pop_cha();
char pop_op();
void inorder(node);
void preorder(node);
void postorder(node);
int prec(char);
float evaluate(node);

node create()
{
	return((node)malloc(sizeof(node)));
}

node newnode=NULL,root,temp,nstack[50];			
int optop=-1,ntop=-1,p,i,opstack[50];

main()
{
	char str[50];
	float z;

	printf("\n ENter expression\n");
	scanf("%s",str);
	root=exptree(str);

	printf("\n The inorder expression is:");
	inorder(root);

	printf("\n The preorder expression is:");
	preorder(root);

	printf("The postorder expression is:");
	postorder(root);

	z=evaluate(root);
	printf("\n the result is %f\n",z);
}

node exptree(char str[])
{
	int i;

	for(i=0;str[i]!='\0';i++)
	{
		if(isalnum(str[i]))
		{
			newnode=create();
			newnode->data=str[i];
			newnode->lchild=NULL;
			newnode->rchild=NULL;
			push_cha(newnode);
		}
		else if (str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(str[i]=='('||optop==-1)
				push_op(str[i]);
			else if(prec(str[i])>prec(opstack[optop]))
				push_op(str[i]);
			else
			{
				while((prec(str[i])<=prec(opstack[optop])&&(opstack[optop]!='('))&&optop>=0)
				{
					newnode=create();
					newnode->data=pop_op();
					newnode->rchild=pop_cha();
					newnode->lchild=pop_cha();
					push_cha(newnode);
				}
				
				push_op(str[i]);
			}
		}
		else if(str[i]==')')
		{
			while(opstack[optop]!='(')
			{
				newnode=create();
				newnode->data=pop_op();
				newnode->rchild=pop_cha();
				newnode->lchild=pop_cha();
				push_cha(newnode);
			}
			pop_op();
		}
		else
			printf("Invalid character\n");
	}
	while(optop!=-1)
	{
		newnode=create();
		newnode->data=pop_op();
		newnode->rchild=pop_cha();
		newnode->lchild=pop_cha();
		push_cha(newnode);
	}

	return pop_cha();
}

void push_cha(node ptr)
{
	ntop=ntop+1;
	nstack[ntop]=ptr;
}

void push_op(char str)
{
	opstack[++optop]=str;
}

node pop_cha()
{
	node ptr;
	ptr=nstack[ntop];
	ntop=ntop-1;
	return ptr;
}

char pop_op()
{
	char d;
	d=opstack[optop];
	optop--;

	return d;
}

int prec(char k)
{

	int p;
	switch(k)
	{
		case '^':p=3; break;
		case '*':p=2;break;
		case'/':p=2;break;
		case '+':p=1;break;
		case '-':p=1;break;
		case '(':p=0;break;
	}

	return p;
}



void inorder(node temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		printf("%c",temp->data);
		inorder(temp->rchild);
	}
}

void preorder(node temp)
{
	if(temp!=NULL)
	{
		printf("%c",temp->data);
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void postorder(node temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);
		postorder(temp->rchild);
		printf("%c",temp->data);
	}
}

float evaluate(node str)
{
	float x,y,z;
	if(str!=NULL)
	{
		if((str->data=='+')||(str->data=='-')||(str->data=='*')||(str->data=='/'))
		{
			x=evaluate(str->lchild);
			y=evaluate(str->rchild);

			switch(str->data)
			{
				case '+':z=x+y;break;
				case '-':z=x-y;break;
				case '*':z=x*y;break;
				case '/':z=x/y;break;
			}
	
			return z;
		}
		
		return (1.0*(str->data-48));
	}
	
	return 0;
}

