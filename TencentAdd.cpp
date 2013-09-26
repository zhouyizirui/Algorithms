#include<iostream>
using namespace std;
int main()
{
	int b[5]={11,8,9,13,4};
	int a[5];

	int temp=1;
	for(int i=0;i<5;i++)	
	{
		temp=b[i]*temp;
	}

	a[0]=1;
	for (int i=1;i<5;i++)
	{
		a[i]=a[i-1]*b[i-1];
	}
	for (int i=4;i>=1;i--)
	{
		a[i]=a[i]*a[0];
		cout<<"The a[] "<<a[0]<<endl;
		a[0]=a[0]*b[i];
	}
	
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<5;i++)
	{
		a[i]=temp/b[i];
	}

	cout<<"The right answer"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
