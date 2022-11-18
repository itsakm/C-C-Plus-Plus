#include<stdio.h>
int main()
{
    long int n=0,a[10000]={0},p[10000]={0},i=0,j=0,sum=0;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&a[i],&p[i]);
    }
    i=0;
    sum=sum+(a[i]*p[j]);
    i++;
    while(i<n)
    {
        if(p[j]<p[i])
        {
            sum=sum+(a[i]*p[j]);
            i++;
        }
        else
        {
            j=i;
            sum=sum+(a[i]*p[j]);
            i++;
        }    
    }
    printf("%ld",sum);
}