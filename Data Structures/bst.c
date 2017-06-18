/* 
Program 9
Implement Binary Search Tree with different operations (create/insert,search,delete,traversal(inorder,preorder,postorder)
*/



#include <stdio.h>
#include <malloc.h>


typedef struct bst
{
	int data;
	struct bst *left, *right;

}node;

node *get_node( );
void insert(node *, node*);
node *search(node *, int, node **);
node *del(node *, int);
node *succ(node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);


main ( )
{
	int ch,ans,key;
	node *New, *root, *temp, *parent=NULL;

	root=NULL;
	printf("\n \t Program for Binary Search Tree");
	
	do
	{
		//parent=NULL;
  		printf("\n1.Create\n2.Search\n3.Delete\n4.Display\n5.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);

 		switch(ch)
		{
			case 1 :do
				{
					New=get_node( );
					printf("\nEnter the Element:");
					scanf("%d",&New->data);
	
					if(root==NULL)
						root=New;
					else
      						insert(root,New);

     					printf("Do u want to conitnue enter more elements(1(yes)/0):\t");
					scanf("%d",&ans);
				}while(ans!=0);
				break;

			case 2 :printf("\nEnter the element which u want to search");
				scanf("%d",&key);

				temp=search(root,key,&parent);
    			
				if(temp!=NULL)
					printf("\nThe %d Element is present",temp->data);
				else
                                        printf("\nElement Not Found\n");

    				if(parent!=NULL&&temp!=NULL)
      					printf("\nParent of node %d is %d\n", temp->data,parent->data);
				break;

 			case 3 :printf("\nEnter the Element u wish to delete:\t");
				scanf("%d",&key);

  				root=del(root,key);
				break;

			case 4 :if(root==NULL)
					printf("\nEmpty Tree\n");
				else
				{
   					printf("\nThe tree in preorder is : ");
   					preorder(root);

  					printf("\nThe tree in inorder is : ");
   					inorder(root);

   					printf("\nThe tree in postorder is : ");
   					postorder(root);
					
					printf("\n");
  				}
  				break;
 		}
 	}while(ch!=5);
}

node *get_node( )
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

void insert(node *root,node *New)
{
 	if(New->data<root->data)
		if(root->left==NULL)
			root->left=New;
		else
			insert(root->left,New);
	else if(New->data>root->data)
 		if(root->right==NULL)
			root->right=New;
		else
			insert(root->right,New);
}

node *search(node *root,int key, node **parent)
{
	node *temp;
	temp=root;
	*parent=NULL;

 	while(temp !=NULL)
	{
		if(temp->data==key)
   			return temp;

 		*parent=temp;
		if(temp->data>key)
			temp=temp->left;
		else
			temp=temp->right;
	}
	return NULL;
}

void inorder(node *temp)
{
 	if(temp !=NULL)
	{
   		inorder(temp->left);
		printf("%d ", temp->data);
		inorder(temp->right);
  	}
}

void preorder(node *temp)
{

	if(temp !=NULL)
	{
		printf("%d ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(node *temp)
{
	if(temp !=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ", temp->data);
	}
}





node *del(node* root,int key)
{
 	node *temp,*parent,*temp_succ;
 	int del_item,cas=0;

 	temp=search(root,key,&parent);
 	//printf("DATAS CONCERNED WITH DELETION: \n parent:%d,  temp:%d",parent->data,temp->data);
	
	if(temp!=NULL)
	{
		if(temp->left==NULL &&temp->right==NULL)
			cas=1;
		else if(temp->left!=NULL&&temp->right!=NULL)
			cas=3;
		else
			cas=2;

		if(cas!=3)
			printf("\nElement is deleted\n");
	}
	else
		printf("Element not found");
	
	if(cas==1)
	{	 
  	 	if(parent!=NULL)
		{
			if(parent->left==temp)
  		  		parent->left=NULL;
			else
   		 		parent->right=NULL;
		}
		else
	 		root=NULL;

		return root;
	}
	else if(cas==2)
	{
		if(parent!=NULL)
		{
			if(parent->left==temp)
			{
				if(temp->left==NULL)
					parent->left=temp->right;
				else
					parent->left=temp->left;
			}
			else if(parent->right==temp)
			{
				if(temp->left==NULL)
					 parent->right=temp->right;
				else
					parent->right=temp->left;
			}
		}
		else
		{
			if(temp->left==NULL)
			{
				root=temp->right;
				//parent->data=parent->right->data;
				//parent->right=NULL;
			}
			else
			{
				root=temp->left;
				//parent->data=parent->left->data;
				//parent->left=NULL;
			}
			
		}
		return root;
	}
	else if(cas==3)
	{
		temp_succ=succ(temp);
		del_item=temp_succ->data;
		root=del(root,del_item);
		temp->data=del_item;
		return root;
	}
}

node *succ(node *ptr)
{
	node *ptr1;
	ptr1=ptr->right;
	if(ptr1!=NULL)
	{
		 while(ptr1->left!=NULL)
             		ptr1=ptr1->left;
	}
return ptr1;
}

