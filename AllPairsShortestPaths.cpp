//all pairs shortest paths
//slowest algo with theta(n^3.logn)
//optimisation done by focusing on the calculation of L(n-1) ... which is done by repeated squaring
#include<iostream>
using namespace std;
int min(int a,int b)
{
	if(a<b)
	return a;
	else return b;
}
int** ExtendShortestPaths(int**L,int**W,int n)
{
	int**LL=new int*[n];
	for(int k=0;k<n;k++)
	{
		LL[k]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			LL[i][j]=1000000000;
			for(int k=0;k<n;k++)
			{
				LL[i][j]=min(LL[i][j],L[i][k]+W[k][j]);
			}
		}
	}
	return LL;
}
int** shortestPaths(int**W,int n)
{
	int**L=W;
	int m=1;
	int**LL;
	while(m<n-1)
	{
		LL=ExtendShortestPaths(L,L,n);//ll=l^2
		m=2*m;//log(n-1) times while loop
		L=LL;
	}
	return LL;
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
	int**G=shortestPaths(W,n);
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
