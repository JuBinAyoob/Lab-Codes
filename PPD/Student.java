
import java.io.*;

class detail
{
 
 int regno;
 String name;
 int mark[]= new int[6];
 int total=0;
 int i;

 void getdata()throws IOException
{
 BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
 System.out.println("enter the name of the student");
 name=br.readLine();
  System.out.println("enter the regno of the student");
 regno=Integer.parseInt(br.readLine());
 System.out.println("enter the marks of the 6 subjects");
for(i=0;i<6;i++)
 {
 mark[i]=Integer.parseInt(br.readLine());

 }
}

void calculation()
{

 for(i=0;i<6;i++)
 {
  total=total+mark[i];
 }
}

 void display()
 {

   
    System.out.print(regno+"\t"+name+"\t");
   // System.out.printf("%1$15S");
   for(i=0;i<6;i++)
 {
    System.out.print(mark[i]+"\t");
 }
  System.out.println(total);

 }
};
public class Student
{
 

 

 public static void main (String[] args)throws IOException
 {
int n,i;
 BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

detail d[]=new detail[10];
 System.out.println("enter the limit");
 n=Integer.parseInt(br.readLine());
 for(i=0;i<n;i++)
 {
d[i]= new detail();  
d[i].getdata();
  d[i].calculation();
  
 }
System.out.println("Regno\tName\t\tm1\tm2\tm3\tm4\tm5\tm6\ttotal");
 for(i=0;i<n;i++)
{
 d[i].display();
}
 }

};


