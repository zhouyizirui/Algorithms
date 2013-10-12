#include<iostream>
using namespace std;
void display(int *a,int length);
void partition(int *a,int head,int end);
int main()
{
	int a[25]={6,9,8,15,89,71,1,7,9,77,3,55,2,5,11,10,12,21,4,43,0,90,17,56,41};
	display(a,25);
	partition(a,0,24);
	display(a,25);
	return 0;
}
void display(int *a,int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void partition(int *a,int head,int end)
{
	int temp=a[head];
	int swap;
	int i=head;
	int j=end;
	while(j>i)
	{
		while(a[i]<=temp && i<end)
			i++;
		while(a[j]>=temp && j>head)
			j--;
		cout<<"i "<<i<<" j "<<j<<endl;
        if(j>i)
		{
			swap = a[j];
			a[j] = a[i];
			a[i] = swap;
		}
	}
	swap = a[head];
	a[head] = a[j];
	a[j] = swap;
	display(a,25);
	if(j>head)	
	{
		cout<<"from "<<head<<" to "<<j<<endl;
		partition(a,head,j);
	}
	if(i<end)
	{	
		cout<<"from "<<i<<" to "<<end<<endl;
		partition(a,i,end);
	}
}
