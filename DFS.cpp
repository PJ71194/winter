//DFS
#include<iostream>
#include<vector>
using namespace std;
vector<int> order;
int time=0;
int v;
int *f,*p,*d;
char *color;
void DFSVISIT(int**g,int u)
{
	//cout<<u<<endl;
	time=time+1;
	d[u]=time;
	color[u]='g';
	for(int i=0;i<v;i++)
	{
		if(g[u][i]==1 && color[i]=='w')
		{
			p[i]=u;
			DFSVISIT(g,i);
		}
	}
	color[u]='b';
	time=time+1;
	f[u]=time;
	order.push_back(u);
	return ;
}
void DFS(int **g,int v)
{
	color=new char[v];
	d=new int[v];
	f=new int[v];
	p=new int[v];
	for(int i=0;i<v;i++)
	{
		color[i]='w';
		d[i]=-1;
		f[i]=-1;
		p[i]=0;
	}
	for(int i=0;i<v;i++)
	{
		if(color[i]=='w')
		{
			DFSVISIT(g,i);
			cout<<i<<endl;
		}
	}
	return ;
}
int main()
{
	cout<<"enter the no. of vertices"<<endl;
	cin>>v;
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
	DFS(a,v);
	for(int i=0;i<order.size();i++)
	{
		cout<<order[i]<<","<<f[order[i]]<<endl;
	}
	return 0;
}
