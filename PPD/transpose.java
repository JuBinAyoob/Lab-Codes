import java.io.*;

class transpose
{
	public static void main(String[] args)throws IOException
	{
		int i,j,m,n;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("enter the number of rows in matrix ");
		m=Integer.parseInt(br.readLine());
		
		System.out.println("enter the number of column in matrix ");
		n=Integer.parseInt(br.readLine());
		int mat[][]=new int[m][n];
		
		System.out.println("Enter elements:\n");
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				mat[i][j]=Integer.parseInt(br.readLine());

		int t[][]=new int[n][m];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				t[j][i]=mat[i][j];

		System.out.println("the transpose of matrix is ");
		
		for(i=0;i<n;i++)
		{
			System.out.println("\n ");
			for(j=0;j<m;j++)
				System.out.print(t[i][j]+" ");
		}
		System.out.println("\n ");
	}
}



