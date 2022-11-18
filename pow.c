#include<stdio.h>
#include<math.h>
int main()
{
    long int sum=0,mod=1000000007,n=0,i=0,d=0;
    scanf("%ld",&n);
    for(i=2;i<=9;i++)
    {
        if(i==5)
        {
            sum=sum+5;
            continue;    
        }
        d=pow(i,n);
        sum=sum+(d%10);
    }
    printf("%ld",sum%mod);
}