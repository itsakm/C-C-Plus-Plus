#include<stdio.h>
#include<math.h>
void primeFactors(long int);
int main()
{
    long int n=0,count=0,i=0;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            
        }
        /*if((i%2==0||i%3==0||i%5==0)&&i%7!=0)
        {
            printf("%ld\n",i);
            count++;
        }*/
    }
    printf("%ld",count);
}
