//heap sort
#include<iostream>
using namespace std;

void heapify(vector<int> *v,int i,int size)
{
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if(l<size && v[l]>v[i])
	{
		largest=l;
	}
	else
	largest=i;
	if(r<size && v[r]>v[largest])
	largest=r;
	if(largest!=i)
	{
		int temp=v[i];
		v[i]=v[largest];
		v[largest]=temp;
		heapify(v,largest)
	}
}
void buildHeap(vector<int> *v)
{
	int length=v->size();
	for(int i=(length-1)/2;i>0;i--)
	{
		heapify(v,i,length);
	}
}
void heapsort(vector<int> *v)
{
	buildHeap(v);
	int length=v->size();
	int a=length;
	for(int i=1;i<a;i++)
	{
		int temp=v[1];
		v[1]=v[length];
		v[length]=temp;
		length--;
		heapify(v,1,length);
	}
}
