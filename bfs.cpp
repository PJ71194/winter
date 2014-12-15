//BFS
#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int data;
	node *link;
};
class queue
{
	public:
	node *first;
	void enqueue(int val)
	{
		node *newNode=new node();
		newNode->data=val;
		if(first==NULL)
		first=newNode;
		else
		{
			node *current=first;
			while(current->link!=NULL)
			{
				current=current->link;
			}
			current->link=newNode;
		}
	}
	int dequeue()
	{
		node *current=first;
		int a;
		if(current==NULL)
		cout<<"list is empty";
		else if(current->link==NULL)
		{
			a=first->data;
			first=NULL;
			return a;
		}
		else
		{
			 a=first->data;
			first=current->link;
			return a;
		}
	}
	queue()
	{
		first=NULL;
	}
};
void BFS(int**g,int s,int v)
{
	//cout<<s<<" "<<v<<endl;
	char *color=new char[v];
	int *d=new int[v];
	int *p=new int[v];
	vector<int> order;
	color[s]='g';
	d[s]=0;
	p[s]=NULL;
	for(int i=0;i<v;i++)
	{
		if(i!=s)
		{
			color[i]='w';
			d[i]=-1;
			p[i]=NULL;
		}
		
	}
	queue q;
	q.enqueue(s);
	//cout<<q.first->data<<endl;
	while(q.first!=NULL)
	{
		int u=q.dequeue();
		//cout<<u<<endl;
		//checking the adjacency matrix for u
		for(int i=0;i<v;i++)
		{
			//cout<<"for"<<endl;
			if(g[u][i]==1 && color[i]=='w')
			{
				//cout<<i<<endl;
				color[i]='g';
				d[i]=d[u]+1;
				p[i]=u;
				q.enqueue(i);
			}
		}
		color[u]='b';
		order.push_back(u);
	}
	for(int k=0;k<order.size();k++)
	{
		cout<<order[k]<<" ";
	}
	cout<<endl;
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
	BFS(a,s,v);
	return 0;
}
