#include<stdio.h>
int main()
{
    int num=0,k=0;
    scanf("%d",&num);
    scanf("%d",&k);
    int n=num;
    int prob[num];
    for(int i=1;i<=num;i++)
    {
        prob[i]=i;
    }
    while(n!=1)
    {
        int a[n-1]; 
        for(int i=1;i<=(n-1);i++)
        {
            if((k+i)>n)
            {
                a[i]=prob[(k+i)-n];
            }
            else
            {
                a[i]=prob[k+i];
            }   
        }
        for(int i=1;i<=(n-1);i++)
        {
            prob[i]=a[i];
        }
        --n;
    }
    printf("%d",prob[1]);
}