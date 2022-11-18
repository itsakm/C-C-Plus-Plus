#include<stdio.h>
#include<conio.h>
int main()
{
	int n=0;
	for(int i=4;i>=0;i--)
	{
		int s=0;
		char ch='A';
		for(int j=0;j<(i-s);j++)
		{
			printf("%c",ch+j);
		}
		for(int k=0;k<n*2;k++)
		{
			printf(" ");
		}
		for(int j=(i-s);j>=0;j--)
		{
			printf("%c",ch+j);
		}
		printf("\n");
		n++;
	}

}