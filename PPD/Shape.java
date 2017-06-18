import java.io.*;

class Shape
{
	double a,b,area;

	void display(String name)
	{
		System.out.println("Area of "+name+" is "+area);
		System.out.println();
		System.out.println();
	}

	public static void main(String[] args)throws IOException
	{
		double ln,brd,arc1,arc2,radius,side;

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		System.out.println();

		//rectangle section

		System.out.println("Enter the length: ");
		ln=Double.parseDouble(br.readLine());

		System.out.println("Enter the breadth: ");
                brd=Double.parseDouble(br.readLine());

		rectangle r=new rectangle(ln,brd);
                r.rectarea();

		//circle section

		System.out.println("Enter the radius: ");
                radius=Double.parseDouble(br.readLine());

		circle c=new circle(radius);
                c.circlearea();

		//square section

                System.out.println("Enter the side: ");
                side=Double.parseDouble(br.readLine());

		square s=new square(side);
                s.squarearea();

		//eclipse section

                System.out.println("Enter the arch1: ");
                arc1=Double.parseDouble(br.readLine());

                System.out.println("Enter the arch2: ");
                arc2=Double.parseDouble(br.readLine());

                eclipse e=new eclipse(arc1,arc2);
                e.eclipsearea();
		
	}
}

class rectangle extends Shape
{
	double a,b;

	rectangle(double length,double breadth)
	{
		a=length;
		b=breadth;
	}

	void rectarea()
	{
		area=a*b;

		display("Rectangle");
	}
}

class circle extends Shape
{
	double a;

        circle(double radius)
        {
                a=radius;
        }

        void circlearea()
        {
                area=3.14*a*a;
        
                display("Circle");
        }
}

class square extends Shape
{
	double a;

        square(double side)
        {
                a=side;
        }

        void squarearea()
        {
                area=a*a;
        
                display("Square");
        }
}

class eclipse extends Shape
{
	double a,b;
	
        eclipse(double arc1,double arc2)
        {
                a=arc1;
                b=arc2;
        }

        void eclipsearea()
        {
                area=3.14*a*b;
        
                display("Eclipse");
        }
}

