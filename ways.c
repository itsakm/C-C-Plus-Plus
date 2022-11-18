#include<stdio.h>
int main()
{
    int n=0,i=0,j=0;
    long int val[1000]={0},count[1000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&val[i]);
        if(val[i]%2==0)
        {
            count[i]=count[i]+((val[i]/2)-1);
        }
        else if(val[i]%2!=0)
        {
           count[i]=count[i]+(val[i]/2); 
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%ld\n",count[j]);
    }

}