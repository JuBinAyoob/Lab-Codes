import java.io.*;

public class Circle
{
	public static void main(String[] args)
	{
		int radius=0;

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter Radius:   ");

		try
		{
			radius=Integer.parseInt(br.readLine());
		}catch(Exception e){}

		double area=Math.PI*radius*radius;

		System.out.println("Area of circle("+radius+")= "+area);
	}
}
