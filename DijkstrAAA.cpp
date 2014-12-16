//DIJKSTRA
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int v;
int *pi,*d;
void dijkstra(int **g,int s)
{
	vector<int> seti;
	set<int> myset;
	seti.push_back(s);
	myset.insert(s);
	for(int i=0;i<v;i++)
	{
		d[i]=1000000000;
		pi[i]=NULL;
	}
	d[s]=0;
	while(seti.size()!=v)
	{
		for(int j=0;j<v;j++)
		{
			set<int>::iterator it=myset.find(j);
			if(it==myset.end())
			{
				if(g[seti.back()][j]!=0 && (g[seti.back()][j]+d[seti.back()]<d[j]))
				{
					d[j]=g[seti.back()][j]+d[seti.back()];
					pi[j]=seti.back();
				}
			}
		}
		int min=1000000000,ui,vi;
		for(int i=0;i<v;i++)
		{
			set<int>::iterator it=myset.find(i);
			if(it==myset.end())
			{
				if(d[i]<min)
				{
					min=d[i];
					ui=pi[i];
					vi=i;
				}
			}
		}	
		seti.push_back(vi);
		myset.insert(vi);	
	}	
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
	dijkstra(a,s);
	for(int i=1;i<v;i++)
	{
		cout<<d[i]<<endl;
	}
	return 0;
}

