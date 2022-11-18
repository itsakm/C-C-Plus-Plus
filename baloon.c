#include<stdio.h>
int main()
{
	int t,gb,pb,part,cost[100]={0,0};
	int ch1,ch2,i,k,j;
	scanf("%d\n",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d\n%d\n",&gb,&pb,&part);
		for(j=0;j<part;j++)
		{
			scanf("%d",&ch1);
			if(ch1==1)
			{
				cost[i]=cost[i]+gb;
                printf("%d",cost[i]);
			}
			scanf("%d",&ch2);
			if(ch2==1)
			{
				cost[i]=cost[i]+pb;
			}
		}
	}
	for(k=0;k<t;k++)
	{
		printf("%d\n",cost[k]);
	}
}