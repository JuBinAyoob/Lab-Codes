#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==1||n==0)
		return 1;
	else
		return n*fact(n-1);
}

main()
{
	int n;

	cout<<"\nEnter the num n to find its factorial:\t";
	cin>>n;

	cout<<"\nfact("<<n<<") =\t"<<fact(n)<<"\n\n\n";
}
