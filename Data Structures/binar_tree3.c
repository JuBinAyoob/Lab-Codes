#include<stdio.h>
#include<malloc.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

node * get_node();
void insert(node*,node*);
node * search(node*,int,node**);
node * del(node*,int);
void preorder(node*);
void postorder(node*);
void inorder(node*);

main()
{
	int ch,ans,kk;
	int key;
	
	node*new,*root,*temp,*parent=NULL;
	root=NULL;

	printf("\n\tprogram of binary search tree");
	do
	{
		printf("\n1:create\n2:search\n3:delete\n4:display\n5:exit\n");
		printf("enter the choice");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:do
				{
					new=get_node();
					printf("\nenter the elements");
					scanf("%d",&new->data);
				
					if(root==NULL)
						root=new;
					else
						insert(root,new);
					
					printf("\ndo you want to continue (1/0)");
					scanf("%d",&ans);
				}while(ans!=0);
				break;
			case 2:printf("enter the elements to be searched");
				scanf("%d",&key);
				temp=search(root,key,&parent);
				if(temp==NULL)
					printf("\nelement not found\n");
				else if(parent!=NULL)
					printf("\nparent node of %d is %d\n",temp->data,parent->data);
				break;
			case 3:printf("enter the element to be deleted");
				scanf("%d",&key);
				root=del(root,key);
				break;
			case 4:if(root==NULL)
					printf("binary search tree is empty");
				else
				{
					printf("\n\nthe tree in preorder is:\t");
					preorder(root);
					printf("\n\nthe tree in inorer is:\t");
					inorder(root);
					printf("\n\nthe tree in post order is:\t");
					postorder(root);
				}break;
		}
	}while(ch!=5);
}

node * get_node()
{
	node *temp;

	temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
 	temp->right=NULL;
	return temp;
}

void insert(node*root,node*new)
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

node * search(node *root,int key,node **parent)
{
 	node *temp;
 	temp=root;
	*parent=NULL;

	while(temp!=NULL)
 	{
		if(temp->data==key)
		{
			printf("the  element %d is present",temp->data);
			return(temp);
		}
		
		*parent=temp;
		if(temp->data>key)
			temp=temp->left;
		else
			temp=temp->right;
	}

	return NULL;
}

node * del(node *root,int key)
{
	node *temp,*parent,*temp_succ;
	temp=search(root,key,&parent);
	if(parent!=NULL)
	{
		printf("hello%u\n",parent);
		if(temp->left!=NULL&&temp->right!=NULL)
		{
			parent=temp;
			temp_succ=temp->right;
			printf("hello");

			if(temp_succ->left==NULL)
			{
				temp->data=temp_succ->data;
				temp->right=temp_succ->right;
			}
			else
			{
				while(temp_succ->left!=NULL)
				{
					parent=temp_succ;
					temp_succ=temp_succ->left;
				}
			
				temp->data=temp_succ->data;
				parent->left=temp_succ->right;
			}
		
			printf("now deleted it!");
			return(root);
		}
		if(temp->left!=NULL&&temp->right==NULL)
		{
			printf("hello2");
			
			if(parent!=NULL)
			{
				if(parent->left==temp)
					parent->left=temp->left;
				else
					parent->right=temp->left;
				
				temp=NULL;
				free(temp);
			}
		}
		else
		{
			printf("parent %u temp %u",parent,temp);
			root=temp->left;
			printf("root->data=%d",root->data);
			temp=NULL;
			free(temp);
		}
		
		printf("now deleted it!");
		return(root);
	}

	if(temp->left==NULL&&temp->right!=NULL)
	{
		printf("hello3");
		if(parent!=NULL)
		{
			if(parent->left==temp)
				parent->right=temp->right;
			temp=NULL;
			free(temp);
		}
		else
		{
			root=temp->right;
			temp=NULL;
			free(NULL);
		}
		printf("now deleted it!");
		return(root);
	}
	
	if(temp->left==NULL&&temp->right==NULL)
	{
		printf("hello4");
		if(parent!=NULL)
		{
			if(parent->left==temp)
				parent->left=NULL;
			else
				parent->right=NULL;
		}
		else
			root=NULL;

		printf("now deleted it!");
		return(root);
	}
}

void inorder(node*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

void preorder(node*temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(node*temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}



