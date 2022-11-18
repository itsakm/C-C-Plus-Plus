#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	int a[100];
	scanf("%d",&n);
	int i=0;
	for(i=0;n>0;i++)
	{
		a[i]=n%2;
		n=n/2;
	}
	for(int j=i-1;j>=0;j--)
	{
		printf("%d\n",a[j]);
	}
}