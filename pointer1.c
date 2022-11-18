#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;

	int *b=malloc(sizeof(int)*10);
	printf("%d",*b);
}