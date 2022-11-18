#include<stdio.h>
int lcm(int ,int);
int main()
{
    int n,i,num,minlcm=0,min=0,c[1000],d[1000],j=0,k=0;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%d",&num);
        minlcm=lcm(1,num-1);
        for(i=1;i<num/2;i++)
        {
            min=lcm((i+1),(num-1-i));
            if(min<minlcm)
            {
                minlcm=min;
                c[k]=(i+1);
                d[k]=(num-1-i);
            }
            else
            {
                c[k]=1;
                d[k]=num-1;
            }
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%d %d\n",c[j],d[j]);
    }
}
int lcm(int a,int b)
{
    int max,i,lcm;
    max=(a > b)?a:b;
    i = max;
    while(1)
    {
        if(i%a==0 && i%b==0)
        {
            lcm = i;
            break;
        }
        i += max;
    }
    return lcm;
}