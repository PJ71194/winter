//Floyd Warshall
//theta(n^3)
//dp algorithm for all pairs shortest paths
#include<iostream>
using namespace std;
int min(int a,int b)
{
	if(a<b)
	return a;
	else return b;
}
int** FloydWarshall(int**W,int n)
{
	int**D=W;
	int**DD;
	for(int i=0;i<n;i++)
	{
		DD=new int*[n];
		for(int j=0;j<n;j++)
		{
			DD[j]=new int[n];
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				DD[j][k]=min(D[j][k],D[j][i]+D[i][k]);
			}
		}
		D=DD;//for recursion
	}
	return DD;
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
	int**G=FloydWarshall(W,n);
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
