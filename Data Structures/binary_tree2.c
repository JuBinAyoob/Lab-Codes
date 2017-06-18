#include<stdio.h>
#include<malloc.h>
typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

node * getnode();
void insert(node*,node*);
node * search(node*,int,node**);
node * del(node*,int);
void preorder(node*);
void inorder(node*);
void postorder(node*);

main()
{
	int ch,key;
	char ans='N',kk;
	node *new,*temp,*parent=NULL,*root=NULL;

	printf("\n the program for binary\n");
	do
	{
		printf("\n 1.CREATE\n 2.SEARCH\n 3.DELETE\n 4.DISPLAY\n 5.EXIT \n");
		printf("enter the choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:do
				{
					new=getnode();
					printf("\n Enter the elements");
					scanf("%d",&new->data);
					
					if(root==NULL)
						root=new;
					else
						insert(root,new);
			
					printf("do u want to continue or else");
					scanf("%c %c",&kk,&ans);
				}while(ans!='N'||ans!='n');
				break;
			case 2:printf("enter the data to be search");
				scanf("%d",&key);
				temp=search(root,key,&parent);
				
				if(temp==NULL)
					printf("element not found");
				else
					printf("%d",temp->data);
				break;
			case 3:printf("enter the data to be deleted");
				scanf("%d",&key);
				root=del(root,key);
				break;
			case 4:if(root==NULL)
					printf("empty tree");
				else
				{
					preorder(root);
					inorder(root);
					postorder(root);
				}
			break;
		}
	}while(ch!=5);
}

node * getnode()
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(node *root,node *new)
{
	if(new->data<root->data)
		if(root->left==NULL)
			root->left=new;
		else
			insert(root->left,new);
	else if(new->data>root->data)
		if(root->right==NULL)
			root->right=new;
		else
			insert(root->right,new);

}

node * del(node * root,int key)
{
	node *temp,*parent,*temp_succ;
	
	*temp=NULL;
	int item;
	temp=search(root,key,&parent)
	{
if(temp!=NULL)
{
if(temp->left==NULL&&temp->right==NULL)
case=1;
else if(temp->left!=NULL&&temp->right==NULL)
case=2;
else
case=3;
printf("element not found");
if(case==1)
{
if(parent!=temp)
{
if(parent->left==temp)
parent

