#include<iostream>
#define max 50
using namespace std;

class stack
{

	public:
	int s[max+1];
	int top;


	stack()
	{
		top=-1;
	}

	void push(int);

	void traverse()
	{
		for(int i=top;i>=0;i--)
			cout<<"   "<<s[i];
		cout<<"\n";
	}

	

	
};

void stack :: push(int data)
{
	if(top==max)
		cout<<"\noverflow\n";
	else
		s[++top]=data;

}

main()
{
	stack JuB;

	int i;
	for(i=0;i<10;i++)
		JuB.push(i*10);

	JuB.traverse();
}
