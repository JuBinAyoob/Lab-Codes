#include<iostream>
using namespace std;

class A
{
	int a;

	public:

	int b;

	int geta();
	void getab();
};

class B :public A
{
	int c;

	public:
	void mul();
	void dis();
};

int A :: geta()
{
	return a;
}

void A :: getab()
{
       	cout<<"Enter a and b:\t";
        cin>>a>>b;
}

void B :: mul()
{
	getab();

	c=b*geta();
}

void B :: dis()
{
	cout<<"\n"<<geta()<<"*"<<b<<"="<<c<<"\n";
}

main()
{
	B cass;

	cass.mul();
	cass.dis();

	cout<<"\n\n"<<cass.geta()<<"     "<<cass.b<<"\n";
}
