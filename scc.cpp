//strongly connected
#include<iostream>
#include<vector>
using namespace std;
int time=0;
int v;
int *f;
char *color;
vector<int> order;
bool hold=false;
void DFSVISIT(int**g,int u)
{
	time=time+1;
	color[u]='g';
	for(int i=0;i<v;i++)
	{
		if(g[u][i]==1 && color[i]=='w')
		{
			DFSVISIT(g,i);
		}
	}
	time=time+1;
	f[u]=time;
	if(hold==false)
	{
		order.push_back(u);
	}
	return;
}
void DFS(int **g,int v)
{
	color=new char[v];
	f=new int[v];
	for(int i=0;i<v;i++)
	{
		color[i]='w';
		f[i]=-1;
	}
	if(hold==false)
	{
		for(int i=0;i<v;i++)
		{
			if(color[i]=='w')
			{
				DFSVISIT(g,i);
			}
		}
	}
	else
	{
		for(int i=order.size()-1;i>=0;i--)
		{
			if(color[order[i]]=='w')
			{
				DFSVISIT(g,order[i]);
				int j=i;
				while(j>=0)
				{
					if(color[order[j]]=='g')
					{
						color[order[j]]='b';
						cout<<order[j];
					}
					j--;
				}
				cout<<" ";
			}
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
	cout<<endl;
	DFS(a,v);
	hold=true;
	for(int i=0;i<v;i++)
	{
		color[i]='w';
		f[i]=-1;
	}
	for(int i=0;i<v;i++)
	{
		for(int j=i;j<v;j++)
		{
			int temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		} 
	}  
	DFS(a,v);
	return 0;
}
