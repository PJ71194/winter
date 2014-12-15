//prim's algo for minimum spanning tree
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void MST(int**g,int r,int V)
{
	set<int> set1;
	set1.insert(r);
	int next,hold;
	vector<int> T;
	set<int>::iterator it;
	while(set1.size()!=V)
	{
		int min=100000000;
		for(it=set1.begin(); it!=set1.end(); ++it)
		{
			for(int j=0;j<V;j++)
			{
				set<int>::iterator i=set1.find(j);
				if(i==set1.end())
				{
					if(g[*it][j]<min && g[*it][j]!=0)
					{
						min=g[*it][j];
						next=j;
						hold=*it;
					}
				}	
			}
		}
		cout<<"("<<hold<<","<<next<<") "<<g[hold][next]<<endl;
		set1.insert(next);
	}
	return;
}
int main()
{
	int v;
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
	int s;
	cout<<"enter the source"<<endl;
	cin>>s;
	MST(a,s,v);
	return 0;
}
