import java.io.*;

class Vectors
{
	double a1,a2,b1,b2,r,im;

	void display(String name)
	{
		System.out.println(name+r+"+"+im+"i)");
		System.out.println();
		System.out.println();
	}

	public static void main(String[] args)throws IOException
	{
		double r1,im1,r2,im2;

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		System.out.println();

		
		System.out.println("Enter the real part and imaginary parts of first complex number: ");
		r1=Double.parseDouble(br.readLine());
		im1=Double.parseDouble(br.readLine());

		System.out.println("Enter the real part and imaginary parts of second complex number: ");
                r2=Double.parseDouble(br.readLine());
                im2=Double.parseDouble(br.readLine());

		operation op=new operation(r1,im1,r2,im2);
                op.addition();
		op.substraction();
		op.multiplication();
		op.divition();
		
	}
}

class operation extends Vectors
{

	operation(double r1,double im1,double r2,double im2)
	{
		a1=r1;
		b1=im1;
		a2=r2;
		b2=im2;
	}

	void addition()
	{
		real re=new real(a1,b1,a2,b2);
		r=re.addition();

		complex co=new complex(a1,b1,a2,b2);
		im=co.addition();

		display("Sum is (");
	}

	void addition()
        {
                real re=new real(a1,b1,a2,b2);
                r=re.add();

                complex co=new complex(a1,b1,a2,b2);
                im=co.addition();

                display("Sum is (");
        }

	void substraction()
        {
                real re=new real(a1,b1,a2,b2);
                r=re.sub();

                complex co=new complex(a1,b1,a2,b2);
                im=co.sub();

                display("Difference is (");
        }

	void multiplication()
        {
                real re=new real(a1,b1,a2,b2);
                r=re.mul();

                complex co=new complex(a1,b1,a2,b2);
                im=co.mul();

                display("Product is (");
        }

	void divition()
        {
                real re=new real(a1,b1,a2,b2);
                r=re.div();

                complex co=new complex(a1,b1,a2,b2);
                im=co.div();

                display("Quotient is (");
        }

}

class circle extends Shape
{

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


