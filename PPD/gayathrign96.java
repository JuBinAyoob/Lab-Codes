import java.io.*;
import java.lang.Thread;
class lock{}
class Rew
{
 public static void main(String args[])
 {
 int i;
 rw a[]=new rw[6];
 for(i=0;i<=2;i++)
  a[i]=new rw(i,"reader");
 for(i=3;i<=5;i++)
  a[i]=new rw(i,"writer");
 for(i=5;i>=0;i--)
  a[i].start();
 }
}

class rw extends Threads
{
 static boolen writing=false;
 static int nreader=0;
 static lock l=new lock();
 int i;
 int threadid;
 String name;
 rw(int i,String s)
{
 threadid=i;
 name=s;
}

public void run()
{
 if(name.equals("reader"))
    reading();
 else
    writing();
}

void reading()
{
 int i;
 acquirereadlock();
 for(i=0;i<=2;i++)
 System.out.println(name+":"+"id="+threadid+"val="+i);
 releasereadlock();
 try
 {
 Thread.sleep(1000);
 }catch(Exception e){}
}

void writing()
{
 acquirewritelock();
 for(i=3;i<=5;i++)
 System.out.println(name+":"+"id="+threadid+"val="+i);
 releasewritelock();
 try
 {
 Thread.sleep(1000);
 }catch(Exception e){}
}

void acquirereadlock()
{
synchronized(l)
{
 while(writing)
 try
 {
  l.wait();
 }catch (Exception e){}
 ++nreader;
}
}

void acquirewritelock()
{
synchronized(l)
{
while(nreader>0||writing)
try
 {
 l.wait();
 }catch(Exception e){}
writing=true;
++nreader;
}
}

void releasereadlock()
{
synchronized(l)
{
 --nreader;
 if(nreader==0)
  l.notifyAll();
}
}

void releasewritelock()
{
synchronized(l)
 {
  writing=false;
  l.notifyAll();
 }
}
}
