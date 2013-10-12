#include<iostream>
using namespace std;
void insert(int *a,int &tail,int element);
void swim(int *a,int &tail);
void sink(int *a,int &tail);
int getmax(int *a,int &tail);
void display(int *a,int &tail);
int main()
{
    int tail = -1;
	int input=0;
	int queue[10];
	while(1)
	{
		cout<<"input the element you want to insert ~"<<endl;
		cin>>input;
		if(input<100)
		{
			insert(queue,tail,input);
			display(queue,tail);
        	swim(queue,tail);
			display(queue,tail);
		}
		else if(input>100 && input<200)
		{
			cout<<"The max "<<getmax(queue,tail)<<endl;
			display(queue,tail);
		}
		else
		{
			break;
		}
	}
	return 0;
}
void display(int *a,int &tail)
{
	cout<<"The queue "<<endl;
	for(int i=0;i<=tail;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void sink(int *a,int &tail)
{
	int newindex = 0;
	int candidate = 0;
	int temp;
	while(((newindex+1)*2)-1 <= tail)
	{
		if((newindex+1)*2+1<=tail+1)
		{
			if(a[(newindex+1)*2-1]<a[(newindex+1)*2])
			{
				if(a[(newindex+1)*2]>a[newindex])
				{
					temp = a[(newindex+1)*2];
					a[(newindex+1)*2] = a[newindex];
					a[newindex] = temp;
					newindex = (newindex+1)*2;
				}
				else
				{
					break;
				}
			}
			else
			{	
				if(a[(newindex+1)*2-1]>a[newindex])
				{
					temp = a[(newindex+1)*2-1];
					a[(newindex+1)*2-1] = a[newindex];
					a[newindex] = temp;
					newindex = (newindex+1)*2-1;
				}
				else
				{
					break;
				}	
			}			
		}
		else
		{
			if(a[(newindex+1)*2-1] > a[newindex])
			{
				temp = a[(newindex+1)*2-1];
				a[(newindex+1)*2-1] = a[newindex];
				a[newindex] = temp;
				newindex = (newindex+1)*2-1;
			}
			else
			{
				break;
			}
		}
	}
}
int getmax(int *a,int &tail)
{
	int retval = a[0];
	a[0]=a[tail];
	tail--;
	sink(a,tail);	
	return retval;
}
void insert(int *a,int &tail,int element)
{
	a[tail+1] = element;
	tail++;	
}
void swim(int *a,int &tail)
{
	int temp;
	int newindex=tail;
	while((newindex+1)/2>=1)
	{
		if(a[newindex]>a[(newindex+1)/2-1])
		{
			temp = a[newindex];
			a[newindex] = a[(newindex+1)/2-1];
			a[(newindex+1)/2-1] = temp;
        	newindex = ((newindex + 1) / 2) - 1;
		}
		else
		{
			break;
		}
	}	
}
