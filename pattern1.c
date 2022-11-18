#include<stdio.h>
#include<conio.h>
int main()
{
	int count=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<i;j++)
		{
			count++;
			printf("%d ",count);
		}
		printf("\n");
	}
}