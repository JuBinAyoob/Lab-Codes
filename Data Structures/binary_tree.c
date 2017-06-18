#include<stdio.h>
#include<malloc.h>
typedef struct bst;
{
int data;
struct bst*left,*right;
}node;
node*get-node();
void insert(node*,node*);
node*search(node*,int,node**);
node*del(node*,int);
void preorder(node*);
void postorder(node*);
void inorder(node*);

main()
{
int ch;
char ans='N',kk;
int key;
node*new,*root,*temp,*parent=NULL;
root=NULL;
printf("\n\tProgram for binary search tree\n");
do
{
printf("\n1.Create\n2.search\n3.delete\n4.Display\n5.Exit\n");
printf("Enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:do
	{
		new=get_node();
printf("\nEnter the elements\n");
scanf("%d",&temp->data);
if(root==NULL)
	root=new;
else
	insert(root,new);
	printf("\nDo you want to continue ? (y/n)\n");
	scanf("%c%c",&kk,&ans);
	}
while(ans!='N');
break;
case 2: printf("\nEnter the elements tobe searched :\n");
	scanf("%d",&key);
	temp=seach(root,key,&parent);
	if(temp==NULL)
		printf("\nElements not found\n");
	else
		printf("%d is present",temp->data);
	break;
case 3: printf("Enter the element to be deleted\n");
	scanf("%d",&key);
	root=del(root,key);
	break;
case 4: if(root=NULL)
		printf("Empty tree");
	else
		preorder(root);
		inorder(root);
		postorder(root);
		break;
case 5: exit(0);
}
}
}

node*get_node()
{
node*temp;
temp=(node*)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
return temp;
}
void insert(root,new)
{
if(new->data<root->data)
	{
		if(root->left==NULL)
		{
			root->left==new;
		}
		else
			insert(root->left,new);
	}
if(new->data>root->data)
	{
		if(root->right==NULL)
			root->right=new;
		else
			insert(root->left,new);
	}
}
node*search(node*root,int key,node*parent)
{
node*temp;
temp=root;
*parent=NULL;
while(temp!=NULL)
	{
		if(temp->dta==key)
		{
		
		}
	}
}
