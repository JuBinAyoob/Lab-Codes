import java.util.concurrent.Semaphore;
class RWLock
{
int readercount;
Semaphore mutex;
Semaphore db;
static int data;
RWLock()
{
readercount=0;
data=0;
mutex=new Semaphore(1);
db=new Semaphore(1);
}
void acquiredReadLock(int readerNum)
{
try
{
mutex.acquire();
}catch(InterruptedException e){}
++readercount;
if(readercount==1)
{
try
{
db.acquire();
}catch(InterruptedException e){}
}
System.out.println("Reader"+readerNum+"is requiring data="+data);
mutex.release();
}
void releaseReadLock(int readerNum)
{
try
{
mutex.acquire();
}catch(InterruptedException e){}
--readercount;
if(readercount==0)
{
db.release();
}
mutex.release();
}
void acquireWriteLock(int writerNum)
{
try
{
mutex.acquire();
}catch(InterruptedException e){}
data++;
System.out.println("writer"+writerNum+"is writing data="+data);
}
void releaseWriteLock(int writerNum)
{
db.release();
}
}
class RW
{
public static void  main(String args[])
{
Thread[]readerArray=new Thread[3];
Thread[]writerArray=new Thread[3];
RWLOCK=new RWLOCK;
for(int i=0;i<3;i++)
{
writerArray[i].Start();
readerArray[i].Start();
}
}
}
class Reader extends Thread
{
RWLOCK database;
int readerNum;
Reader(int readerNum,RWLOCK database)
{
this.readerNum=readerNum;
this.database=database;
}
public void run()
{
while(true)
{
try
{
Thread.sleep(1000);
}catch(InterruptedException e){}
database.acquireReadLock(readerNum);
try
{
Thread.sleep(1000);
}catch(InterruptedException e){}
database.releaseReadLock(readerNum);
}
}
}
class Writer extends Thread
{
RWLOCK database;
int writerNum;
Writer(int w,RWLOCK d)
{
writerNum=w;
database=d;
}
public void run()
{
while(true)
{
try
{
Thread.sleep(1000);
}catch(InterruptedException e){}
database.acquireWriteLock(writerNum);
try
{
Thread.sleep(1000);
}catch(InterruptedException e){}
database.releaseWriteLock(writerNum);
}
}
}




