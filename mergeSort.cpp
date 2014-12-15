//merge sort
#include<iostream>
using namespace std;
void merge(int *a,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *L=new int[n1+1];
	int *R=new int[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i]=a[p+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=a[q+1+i];
	}
	L[n1]=-1;
	R[n2]=-1;
	int i=0,j=0;
	for(int k=p;k<=r;k++)
	{
		if(i==n1 && j<n2)
		{
			a[k]=R[j];
			j++;
		}
		else if(j==n2 && i<n1)
		{
			a[k]=L[i];
			i++;
		}
		else if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
}
void MERGESORT(int *b,int p,int q)
{
	if(p==q)
	{
		return ;
	}
	else if(p<q)
	{
		int m=(p+q)/2;
		MERGESORT(b,p,m);
		MERGESORT(b,m+1,q);
		merge(b,p,m,q);
	}
}
int main()
{
	int n;
	cin>>n;
	int *ar=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	MERGESORT(ar,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	return 0;
}
