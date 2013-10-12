#include<iostream>
using namespace std;
int partition(int *a,int head,int end);
int select(int *a,int k,int head,int end);
void display(int *a,int length);
int main()
{
	int k=9;
    int a[15]={24,35,1,19,12,23,11,18,31,42,2,44,23,78,54};
	display(a,15);
	int result = select(a,k,0,14);
	cout<<"The result is "<<result<<endl;
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
int select(int *a,int k,int head,int end)
{
	int retindex;
	retindex=partition(a,head,end);
	cout<<"The retindex "<<retindex<<endl;
	display(a,15);
	while(1)
	{
		if(retindex<k)
		{	
			retindex=partition(a,retindex+1,end);
			cout<<"The minus retindex "<<retindex<<endl;
		}
		else if(retindex>k)
		{
			retindex=partition(a,head,retindex-1);
			cout<<"The large retindex "<<retindex<<endl;
			display(a,15);
		}	
		else
		{
			cout<<"The retindex "<<retindex<<endl;
			return a[retindex];
		}
	}
}
int partition(int *a,int head,int end)
{
	int temp=a[head];
	int swap;
	int i=head;
	int j=end;
	while(i<j)
	{
		while(a[i]<=temp && i<end)
			i++;
		while(a[j]>=temp && j>head)
			j--;
		if(j>i)
		{
			swap = a[j];
			a[j] = a[i];
			a[i] = swap;
		}
	}
	cout<<"i "<<i<<" j "<<j<<endl;
	swap = a[j];
	a[j] = a[head];
	a[head] = swap;
	return j;
}
