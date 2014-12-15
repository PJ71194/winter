//topological sort
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *link;
};
class linkedList
{
	public:
	node *first;
	void insertAtBeg(int val)
	{
		node *newNode=new node();
		newNode->data=val;
		if(first==NULL)
		first=newNode;
		else
		{
			newNode->link=first;
			first=newNode;
		}
	}
	linkedList()
	{
		first=NULL;
	}
};
linkedList l;
int time=0;
int v;
int *f;
char *color;
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
	l.insertAtBeg(u);
	return ;
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
	for(int i=0;i<v;i++)
	{
		if(color[i]=='w')
		{
			DFSVISIT(g,i);
		}
	}
	return ;
}
int main()
{
	cout<<"enter the no. of vertices of the dag"<<endl;
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
	node* temp=l.first;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
	return 0;
}
