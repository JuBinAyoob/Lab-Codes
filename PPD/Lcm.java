import java.io.*;
//import java.lang.Thread;

class node
{
	int data;
	boolean visit;

	node()
	{
		visit=false;
	}

	boolean isvisit()
	{
		return visit;
	}
}

class tree
{
	public static node n[]=new node[20];
	public static int size,x,node1,node2;

	String c;
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

	int read()
	{
		try
		{
			c=br.readLine();
			x=Integer.parseInt(c);
		}catch(IOException e){}

		return x;
	}

	void readthread()
	{
		int i;
		System.out.println("Enter the number of nodes:");
		size=read();

		System.out.println("Enter the elements:");
		for(i=1;i<=size;i++)
		{
			n[i]=new node();
			n[i].data=read();
		}

		System.out.println("Enter the search nodes:");
		node1=read();
		node2=read();

		Search s1=new Search("node 1",node1);
		Search s2=new Search("node 2",node2);
	
		try
		{
			s1.t.join();
			s2.t.join();
		}catch(InterruptedException e){}
	}
}

class Search implements Runnable
{
	int i,j,LCA,node;
	Thread t;

	Search(String name,int n)
	{
		t=new Thread(this,name);
		t.start();
		node=n;
	}

	public void run()
	{
		for(i=1;i<=tree.size;i++)
			if(tree.n[i].data==node)
				break;
		for(j=i/2;j>=1;j=j/2)
		{
			if(tree.n[j].isvisit()==true)
			{
				LCA=tree.n[j].data;

				System.out.println("LCA is:"+LCA+"\n");
				t.stop();
			}
			tree.n[j].visit=true;
		}
	}
}

class Lcm
{

	public static void main(String[] args)
	{
		tree t=new tree();
		t.readthread();
	}	

}
