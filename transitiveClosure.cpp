//transitive closure
//using floyd warshall
#include<iostream>
using namespace std;
int** transitiveClosure(int**g,int n)
{
	int**t=new int*[n];
	for(int i=0;i<n;i++)
	{
		t[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j || g[i][j]!=0)
			{
				t[i][j]=1;
			}
			else
			t[i][j]=0;
		}
	}
	int**T;
	for(int k=0;k<n;k++)
	{
		T=new int*[n];
		for(int i=0;i<n;i++)
		{
			T[i]=new int[n];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				T[i][j]=t[i][j]|(t[i][k]&t[k][j]);
			}
		}
		t=T;
	}
	return T;
}
int main()
{
	int n;
	cin>>n;
	int**W=new int*[n];
	for(int i=0;i<n;i++)
	{
		W[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>W[i][j];
		}
	}
	int**G=transitiveClosure(W,n);
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<G[k][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
