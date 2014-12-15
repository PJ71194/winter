//divide and conquer
#include<iostream>
using namespace std;
int* findMaxCrossingArray(int *a,int low,int mid,int high)
{
	int sum=0;
	int leftSum=-1000000000;
	int rightSum=-1000000000;
	int leftLow;
	int rightHigh;
	for(int i=mid;i>=low;i--)
	{
		sum=sum+a[i];
		if(sum>leftSum)
		{
			leftSum=sum;
			leftLow=i;
		}
	}
	for(int i=mid+1;i<=high;i++)
	{
		sum=sum+a[i];
		if(sum>rightSum)
		{
			rightSum=sum;
			rightHigh=i;
		}
	}
	int *b=new int[3];
	b[0]=leftLow;
	b[1]=rightHigh;
	b[2]=leftSum+rightSum;
	return b;
}
int* findMaxSubarray(int *a,int low,int high)
{
	int *c=new int[3];
	if(high==low)
	{
		c[0]=low;
		c[1]=high;
		c[2]=a[low];
		return c;
	}
	int mid=(low+high)/2;
	int *c1=new int[3];
	c1=findMaxSubarray(a,low,mid);
	int *c2=new int[3];
	c2=findMaxSubarray(a,mid+1,high);
	int *c3=new int[3];
	c3=findMaxCrossingArray(a,low,mid,high);
	cout<<c3[0]<<" , "<<c3[1]<<endl;
	if(c1[2]>c2[2] && c1[2]>c3[2])
	return c1;
	else if(c2[2]>c1[2] && c2[2]>c3[2])
	return c2;
	else 
	return c3;
}
int main()
{
	int n;
	cin>>n;
	int *ar=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[n];
	}
	int *b=new int[3];
	b=findMaxSubarray(ar,0,n-1);
	cout<<"the maximum subarray is "<<b[0]<<" to "<<b[1]<<" the max sum is "<<b[2]<<endl;
	return 0;
}
