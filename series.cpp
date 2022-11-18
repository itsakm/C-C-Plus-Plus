#include<conio.h>
#include<iostream>
using namespace std;


float power(float a,float b)
{
	float res=a;
	for(int i=1;i<b;i++)
	{
		res=res*a;
	}
	return res;

}
float fact(float a)
{
	float res=a;
	while(a!=1)
	{
		a--;
		res=res*a;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	float j=1;
	for(int i=1;i<=n;i++)
	{
			
			float a=power(2,j);
			float b=fact(j);
			float c=a/b;
			cout<<c<<"  ";
			j=j+2;
		
	}
}