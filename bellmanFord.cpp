//bellman ford algorithm
#include<iostream>
using namespace std;
int *d,*pi;
int v;
bool Bellman(int**g,int s)
{
	for(int i=0;i<v;i++)
	{
		d[i]=10000000;
		pi[i]=NULL;
	}
	d[s]=0;
	for(int j=0;j<v-1;j++)
	{
		for(int i=0;i<v;i++)
		{
			for(int k=0;k<v;k++)
			{
				if(g[i][k]!=0)
				{
					if(d[k]>(d[i]+g[i][k]))
					{
						d[k]=d[i]+g[i][k];
						pi[k]=i;
					}
				}
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int k=0;k<v;k++)
		{
			if(g[i][k]!=0)
			{
				if(d[k]>(d[i]+g[i][k]))
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	cout<<"enter the no. of vertices"<<endl;
	cin>>v;
	d=new int[v];
	pi=new int[v];
	int **a=new int *[v];
	for(int i=0;i<v;i++)
	{
		a[i]=new int[v];
	} 
	//input graph matrix
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>a[i][j];
		} 
	} 
	int s;
	cout<<"enter source"<<endl;
	cin>>s;
	bool temp=Bellman(a,s);
	cout<<temp<<endl;
	if(temp==true)
	{
		for(int i=0;i<v;i++)
		{
			cout<<d[i]<<" ("<<i<<","<<pi[i]<<")"<<endl;;
		}
	}
	cout<<endl;
	return 0;
}
