#include<iostream>
using namespace std;
void makemaxhead(int *a, int n);
void sink(int *a, int root, int end);
void display(int *a, int length);
void heapsort(int *a, int end);
int main()
{
	int a[10]={2,3,14,18,16,90,21,4,43,72};
	makemaxhead(a,9);
    display(a,10);
	heapsort(a,9);
	display(a,10);
	return 0;
}

void heapsort(int *a, int end)
{
	int temp;
	for(int k = end; k>=0; k--)
	{
		temp = a[0];
		a[0] = a[k];
		a[k] = temp;

		sink(a,0,k-1);
	}	
}

void display(int *a, int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void makemaxhead(int *a, int n)
{
	for (int i=n/2;i>=0;i--)
	{
		sink(a,i,9);
	}
}
void sink(int *a, int root, int end)
{
	int i=root;
    int j=2*root+1;
	int temp = a[root];
	while(j<=end)
	{
		if(j+1 <= end && a[j+1]>a[j])
		{
			j++;
		}
		
		if(a[j]<temp)
		{
			break;
		}
        
        a[i] = a[j];
        i = j;
        j = 2*i+1;
	}
    a[i] = temp;
}
