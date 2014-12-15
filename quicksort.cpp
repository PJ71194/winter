//qucik sort
#include<iostream>
using namespace std;
void quicksort(int *a,int first,int last)
{
	if(first>=last)
	return;
	int pivot=a[first];
	int i=first;
	int j=last;
	while(i<j)
	{
		while(a[i]<pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	quicksort(a,first,i-1);
	quicksort(a,j+1,last);
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

