#include<iostream>
using namespace std;
int main()
{
	int a[20];
    int uniona,unionb;
    int pida,pidb;
	int i;
    for(i=0;i<20;i++)
	{
		a[i] = i;
	}
	while(true)
    {
		cin>>uniona;
		cin>>unionb;
        pida = a[uniona];
		pidb = a[unionb];
		cout<<"Input the union:"<<endl;
		if(uniona==100)
			break;
		for(int i=0;i<20;i++)
		{
			if(a[i]==pida)
			{
				a[i]=pidb;
			}
		}
	} 
    cout<<"The result!"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
