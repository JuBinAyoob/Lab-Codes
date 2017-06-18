import java.io.*;

 class Student
 {
  int r,k;
  String name;
  int m[]=new int[5];
  int tot;
  
  public void read()
   { 
     BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
     try
     {
     System.out.println("enter the register no:");
     r=Integer.parseInt(br.readLine());
     System.out.println("enter the name of student:");
     name=(br.readLine());
     System.out.println("enter the marks of student:");
       for(k=0;k<3;k++)
         {
           m[k]=Integer.parseInt(br.readLine());
          }
         tot=m[0]+m[1]+m[2];
      }catch(Exception e){}
    }


   public void disp()
    {
      
      System.out.print(r+"\t\t"+name+"\t\t"); 
      for(k=0;k<3;k++)
         System.out.print(m[k]+"\t");
       System.out.print(tot+"\n");
         
    }

 }

 public class Stu
 {
   public static void main(String[] args)throws IOException
    {
      int i,j,n;
     
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      System.out.println("enter the no:of students:");
      n=Integer.parseInt(br.readLine());
      Student s[]=new Student[n];
      for(i=0;i<n;i++)
        {
	s[i]=new Student();
         s[i].read();
        }
      System.out.println("regno\t\tname\t\tmark 1\tmark 2\tmark3 \ttotal\n");

      for(i=0;i<n;i++)
        {
         s[i].disp();
        }
     }
 }







