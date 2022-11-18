#include<stdio.h>
int main()
{
    long int n,i,sum=0,mod=998244353;
    char ch[200000]={0};
    scanf("%ld",&n);
    scanf("%s",ch);
    if(n==2)
    {sum=sum+3;}
    else if(n>2)
    {
        sum=sum+3;
        for(i=0;i<n;i++)
        {
            if(ch[i]==ch[i+1])
            {
                sum=sum+1;
            }
            else
            {
                break;
            }    
        }
        for(i=n-1;i>0;i--)
        {
            if(ch[i]==ch[i-1])
            {
                sum=sum+1;
            }
            else
            {
                break;
            }
            
        }
    }
    printf("%ld",sum%mod);
}