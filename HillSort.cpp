#include<iostream>
using namespace std;
void display(int *a,int n);
void hillsort(int *a,int n);
int main()
{
	int a[15]={3,4,56,2,14,9,10,12,34,11,7,3,13,15,90};
    hillsort(a,15);
	display(a,15);
}
void display(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void hillsort(int *a,int n)
{
	int i;
	int j;
	int gap;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<n;j=j+gap)
			{
				if(a[j]<a[j-gap])
				{
					int temp=a[j];
					int k=j-gap;
					while(k>=0 && a[k]>temp)
					{
						a[k+gap]=a[k];
						k-=gap;
					}
					a[k+gap]=temp;
				}
			}
		}
	}
}
