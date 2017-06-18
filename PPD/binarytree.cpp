#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
	public:

	int data;
	node *lchild,*rchild;

	node()
	{
		lchild=NULL;
		rchild=NULL;
	}
};

class tree
{
	public:

	node *root;
	
	void initialize();	

	tree()
	{
		root=NULL;
	}

	void init(node *ptr)
	{
		if(root==NULL)
			root=ptr;
		else
			insert(root,ptr);
	}

	void insert(node *temp,node *ptr)
	{
		int ch;

		cout<<"\nEnter the path('0' for left,'1' for right):\t";
		cin>>ch;

		switch(ch)
		{
			case 0:if(temp->lchild==NULL)
				{
					temp->lchild=ptr;
				}
				else
					insert(temp->lchild,ptr);break;
			case 1:if(temp->rchild==NULL)
                                {
                                        temp->rchild=ptr;
                                }
                                else
                                        insert(temp->rchild,ptr);break;

			default:cout<<"\nInvalid option\n";
		}
	}

	void in_order(node *temp);
	void pre_order(node *temp);
	void post_order(node *temp);


	void traverse()
	{
		int ch;
		
		cout<<"\n\nEnter option \n\t1.inorder \n\t2.preorder \n\t3.postorder \n\nenter:\t";
		cin>>ch;

		switch(ch)
		{
			case 1: in_order(root);break;
			case 2: pre_order(root);break;
			case 3: post_order(root);break;
			default:cout<<"\nInvalid choice\n";
		}
		cout<<"\n";
	}
}tr;

void tree :: initialize()
{
        node *ptr;

        ptr=new node;

        cout<<"\nEnter data to node:\t";
        cin>>ptr->data;

        init(ptr);
}


void tree :: in_order(node *temp)
{
	if(temp!=NULL)
	{
		in_order(temp->lchild);
		cout<<"  "<<temp->data;
		in_order(temp->rchild);
	}
}

void tree :: pre_order(node *temp)
{
        if(temp!=NULL)
        {
		cout<<"  "<<temp->data;
                pre_order(temp->lchild);
                pre_order(temp->rchild);
        }
}

void tree :: post_order(node *temp)
{
        if(temp!=NULL)
        {
                post_order(temp->lchild);
                post_order(temp->rchild);
        	cout<<"  "<<temp->data;
	}
}


main()
{
	int ch;

	while(1)
	{
		cout<<"\n\nEnter ur choice \n\t1.enter element to binarytree \n\t2.traverse \n\t3.exit \n\nenter:\t";
		cin>>ch;

		switch(ch)
		{
			case 1:tr.initialize();break;
			case 2:tr.traverse();break;
			case 3:exit(0);
			default:cout<<"\nInvalid option\n";
		}
	}
}

