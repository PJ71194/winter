//kruskal's algorithm for minimum spanning tree
#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
void merge(int *a,int *U,int *V,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *L=new int[n1+1];
	int *R=new int[n2+1];
	int *UL=new int[n1+1];
	int *UR=new int[n2+1];
	int *VL=new int[n1+1];
	int *VR=new int[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i]=a[p+i];
		UL[i]=U[p+i];
		VL[i]=V[p+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=a[q+1+i];
		UR[i]=U[q+1+i];
		VR[i]=V[q+1+i];
	}
	L[n1]=-1;
	R[n2]=-1;
	int i=0,j=0;
	for(int k=p;k<=r;k++)
	{
		if(i==n1 && j<n2)
		{
			a[k]=R[j];
			U[k]=UR[j];
			V[k]=VR[j];
			j++;
		}
		else if(j==n2 && i<n1)
		{
			a[k]=L[i];
			U[k]=UL[i];
			V[k]=VL[i];
			i++;
		}
		else if(L[i]<=R[j])
		{
			a[k]=L[i];
			U[k]=UL[i];
			V[k]=VL[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			U[k]=UR[j];
			V[k]=VR[j];
			j++;
		}
	}
}
void MERGESORT(int *b,int *ui,int *vi,int p,int q)
{
	if(p==q)
	{
		return ;
	}
	else if(p<q)
	{
		int m=(p+q)/2;
		MERGESORT(b,ui,vi,p,m);
		MERGESORT(b,ui,vi,m+1,q);
		merge(b,ui,vi,p,m,q);
	}
}
void MST(int **g,int ver,int e)
{
	int *w=new int[e];
	int *u=new int[e];
	int *v=new int[e];
	int k=0;
	for(int i=0;i<ver;i++)
	{
		for(int j=i;j<ver;j++)
		{
			if(g[i][j]!=0)
			{
				w[k]=g[i][j];
				u[k]=i;
				v[k]=j;
				k++;
			}
		}
	}
	MERGESORT(w,u,v,0,e-1);
	for(int i=0;i<e;i++)
	{
		cout<<w[i]<<" ("<<u[i]<<","<<v[i]<<") "<<endl;
	}
	int *set=new int[ver];
	for(int i=0;i<ver;i++)
	{
		set[i]=i;
	}
	vector<int> T;
	for(int j=0;j<e;j++)
	{
		if(set[u[j]]<set[v[j]])
		{
			int temp=set[v[j]];
			for(int i=0;i<ver;i++)
			{
				if(set[i]==temp)
				{
					set[i]=set[u[j]];
				}
			}
			T.push_back(w[j]);	
		}
		else if(set[u[j]]>set[v[j]])
		{
			int temp=set[u[j]];
			for(int i=0;i<ver;i++)
			{
				if(set[i]==temp)
				{
					set[i]=set[v[j]];
				}
			}
			T.push_back(w[j]);
		}
	}
	for(int m=0;m<T.size();m++)
	{
		cout<<T[m]<<" ";
	}
	cout<<endl;
	return ;
}
int main()
{
	int v,e;
	cout<<"enter the no. of vertices and edges"<<endl;
	cin>>v>>e;
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
	MST(a,v,e);
	return 0;
}
