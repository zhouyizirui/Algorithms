#include<iostream>
using namespace std;
int main()
{
	int S=15;
	int Min[15];
	int Coin[3];
	Coin[0]=1;
	Coin[1]=3;
	Coin[2]=5;
	for(int i=0;i<15;i++)
	{
		Min[i]=1000;
	}
	Min[0]=0;
	for(int i=0;i<S;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(Coin[j]<=i && Min[i-Coin[j]]+1<Min[i])
			{
				Min[i]=Min[i-Coin[j]]+1;
			}
		}
	}
	for(int i=0;i<15;i++)
	{
		cout<<Min[i]<<" ";
	}
	cout<<endl;
	return 0;
}
