#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define B 10

struct node
{
	int e;
	struct node *next;
};

typedef struct node DICTIONARY;

void Make_NULL(DICTIONARY *A[B])
{
	int i;

	for(i=0;i<B;i++)
	{
		A[i]=(DICTIONARY *)malloc(sizeof(DICTIONARY));
		A[i]=NULL;
	}
}

int Member(DICTIONARY *A[B],int x)
{
	struct node *current;

	current=A[x%B];

	while(current!=NULL)
	{
		if(current->e==x)
			return 1;
		else
			current=current->next;
	}
	return 0;
}

void Insert(DICTIONARY *A[B],int x)
{
	int bucket;
	struct node *old,*temp;

	if(!Member(A,x))
	{
		bucket=x%B;
		old=A[bucket];
		temp=malloc(sizeof(DICTIONARY));
		temp->e=x;
		temp->next=old;
		A[bucket]=temp;
	}
}

int Delete(DICTIONARY *A[B],int x)
{
	struct node *current;
	int bucket;
	
	bucket=x%B;
	
	if(A[bucket]->e==x)
	{
		A[bucket]=A[bucket]->next;
		return 1;
	}
	else
	{
		current=A[bucket];

		while(current->next!=NULL)
		{
			if(current->next->e==x)
			{
				current->next=current->next->next;
				return 1;
			}	
			else	
				current=current->next;
		}
	}
	return 0;
}

void Display(DICTIONARY *A[B])
{
	int i=0;
	DICTIONARY *t=A[i];

	printf("\nBucket elements\n");

	while(i<B)
	{
		t=A[i];
		printf("\n     %d\t",i);

		while(t!=NULL)
		{
			printf("%4d->",t->e);
			t=t->next;
		}
		printf("NULL");
		i++;
	}
	printf("\n");
}


main()
{
	DICTIONARY *A[B];
	int choice,data;

	Make_NULL(A);

	while(1)
	{
		printf("\n............MENU.............\n");
		printf("\n1.insert\n2.member\n3.delete\n4.display\n5.exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("\nEnter the data to be inserted:\t");
			       scanf("%d",&data);
			       Insert(A,data);break;
			case 2:printf("\nEnter data to be checked as a member on present in hash table\n");
			       scanf("%d",&data);
			       data=Member(A,data);

				if(data)
					printf("\nMember\n");
				else
					printf("\nnot a member\n");break;
			case 3: printf("\nenter data to be deleted:\t");
			        scanf("%d",&data);
 			        data=Delete(A,data);

				if(data)
					printf("\nelement deleted\n");
				else
					printf("\nnot amember\n");break;
			case 4:Display(A);break;
			case 5:exit(0);
		}
	}
}
