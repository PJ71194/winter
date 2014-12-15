//insertion sort
#include<iostream>
using namespace std;
void insertionSort(int *a)
{
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
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
	insertionSort(ar);
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	return 0;
}
