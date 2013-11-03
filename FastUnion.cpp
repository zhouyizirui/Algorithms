#include<iostream>
using namespace std;
void theunion(int *a,int *num,int p,int q);
int root(int *a,int p);
bool connected(int *a,int p,int q);
void display(int *a);
int main()
{
    int a[10];
    int num[10];
	int uniona,unionb;
	int pida,pidb;
	for(int i=0;i<10;i++)
	{
		a[i] = i;
        num[i] = 1;
	}
	while(true)
	{
		cin>>uniona;
		cin>>unionb;
		if(uniona>=100)
		{	
			cout<<"Fuck"<<endl;
			break;
		}
		else
		{
			cout<<"Here"<<endl;
			theunion(a,num,uniona,unionb);
		}
	}
	cout<<connected(a,3,6)<<endl;
	return 0;
}
void theunion(int *a,int *num,int p,int q)
{
	int rootp = root(a,p);
	int rootq = root(a,q);
    int nump = num[rootp];
    int numq = num[rootq];
	cout<<"The roota "<<rootp<<" The rootb "<<rootq<<endl;
    if(nump<numq)
	{
		a[rootp] = rootq;
    	num[rootq] = num[rootq]+num[rootp];
	}
	else
	{
		a[rootq] = rootp;
		num[rootp] = num[rootp]+num[rootq];
	}
	cout<<"The a!"<<endl;
	display(a);
	cout<<"The num!"<<endl;
    display(num);
}
void display(int *a)
{
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" "; 
	}
	cout<<endl;
}
int root(int *a,int p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

bool connected(int *a,int p,int q)
{
	return root(a,p) == root(a,q);
}
