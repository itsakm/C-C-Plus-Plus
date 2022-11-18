#include<stdio.h>
#include<conio.h>
int main()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("1");
		}
		printf("\n");
	}
	for(int i=4;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			printf("1");
		}
		printf("\n");
	}
}