#include<iostream>
using namespace std;
void sort(int *a,int *temp,int head,int end);
void merge(int *a,int *temp,int head,int end);
void display(int *a,int length);
int main()
{
	//int a[15]={8,4,12,11,17,1,5,2,6,7,18,9,3,90,14};
	int a[10]={6,3,1,8,2,4,5,9,7,0};
	//int a[8]={6,7,8,9,1,2,14,18};	
	int temp[10];
	display(a,10);
    sort(a,temp,0,9);
	display(a,10);
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
void sort(int *a,int *temp,int head,int end)
{
    int mid = (head+end+1)/2;
	if(head<end)
	{
    	cout<<"The head "<<head<<" ";
    	cout<<"The mid "<<mid<<" ";
    	cout<<"The end "<<end<<" ";
    	cout<<endl;
		sort(a,temp,head,mid-1);
		sort(a,temp,mid,end);
		merge(a,temp,head,end);
	//	display(a,8);
	}
}
void merge(int *a,int *temp,int head,int end)
{
    int mid = (head+end+1)/2;
	for (int i=head;i<=end;i++)
	{
		temp[i] = a[i];
	}
    int j=head;
	int k=mid;
	for(int i=head;i<=end;i++)
	{
		if(j>=mid)
			a[i]=temp[k++];
		else if(k>end)
			a[i]=temp[j++];
		else if(temp[j]<temp[k])
			a[i]=temp[j++];
		else
			a[i]=temp[k++];
	}
}
