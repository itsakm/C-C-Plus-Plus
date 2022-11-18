#include <stdio.h>
void facing(int);
int main(){
	int num,seat,i;
	scanf("%d", &num);       
	for(i=0;i<num;i++)
	{
		scanf("%d",&seat);
		facing(seat);
	}  
	return 1;
}
void facing(int n)
{
	if(n%12==0 || n%12==1 || n%12==6 || n%12==7)
	{
		if(n%12==1)
		{
			printf("%d WS",n+11);
		}
		else if(n%12==0)
		{
			printf("%d WS",n-11);
		}
		else if(n%12==6)
		{
			printf("%d WS",n+1);	
		}
		else if(n%12==7)
		{
			printf("%d WS",n-1);
		}
	}

	else if(n%12==2 || n%12==11 || n%12==5 || n%12==8)
	{
		if(n%12==2)
		{
			printf("%d MS",n+9);
		}
		else if(n%12==11)
		{
			printf("%d MS",n-9);
		}
		else if(n%12==5)
		{
			printf("%d MS",n+3);	
		}
		else if(n%12==8)
		{
			printf("%d MS",n-3);
		}
	}

	else if(n%12==3 || n%12==10 || n%12==4 || n%12==9)
	{
		if(n%12==3)
		{
			printf("%d AS",n+7);
		}
		else if(n%12==10)
		{
			printf("%d AS",n-7);
		}
		else if(n%12==4)
		{
			printf("%d AS",n+5);	
		}
		else if(n%12==9)
		{
			printf("%d AS",n-5);
		}
	}
}
