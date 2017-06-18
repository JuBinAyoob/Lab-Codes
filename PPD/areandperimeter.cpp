#include<iostream>
#include<stdlib.h>
#define Pi 3.14

using namespace std;	

class shape
{
	public:

		float area,perimeter;

		void showdata()
		{
			cout<<"\n\nThe Area :\t"<<area<<"\nThe perimeter :\t"<<perimeter<<"\n";
		}
};

class square : public shape
{
	float side;

	public:
		void getdata()
		{
			cout<<"\nEnter the side of square:\t";
			cin>>side;
		}

		void Area()
		{
			area=side*side;
		}

		void Perimeter()
		{
			perimeter=4*side;
		}

};

class circle : public shape
{
	float radius;

	public:
	 	void getdata()
                {
			cout<<"\nEnter the radius of circle:\t";
                        cin>>radius;
                }

                void Area()
                {
			area=Pi*radius*radius;
                }

                void Perimeter()
                {
			perimeter=2*Pi*radius;
                }

};

class rectangle : public shape
{
	float length,breadth;

	public:
		void getdata()
                {
			cout<<"\nEnter the length and breadth of rectangle:\t";
                        cin>>length>>breadth;
                }

                void Area()
                {
			area=length*breadth;
                }

                void Perimeter()
                {
			perimeter=2*length+2*breadth;
                }
};

main()
{
	int ch;
	while(1)
	{
		cout<<"\nChoice the shape \n\t1.square \n\t2.circle \n\t3.rectangle \n\t4.exit \n\nEnter your choice...";
		cin>>ch;

		switch(ch)
		{
			case 1:	square s;
				s.getdata();
				s.Area();
				s.Perimeter();
				s.showdata();
				break;

			case 2: circle c;
                        	c.getdata();
                        	c.Area();
                        	c.Perimeter();
                        	c.showdata();
                        	break;
			case 3: rectangle r;
                        	r.getdata();
                        	r.Area();
                        	r.Perimeter();
                        	r.showdata();
                        	break;
			case 4:exit(0);
			default:cout<<"\ninvalid Option\n";

		}
	}
}
