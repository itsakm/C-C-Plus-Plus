#include<stdio.h>
int main()
{
    
    long int n,i,no,ch,a[200000],sum=0,j,temp;
    scanf("%d",&n);
    scanf("%d",&no);
    scanf("%d",&ch);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum=sum+a[ch-1];
    no--;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=1;j--)
            {
            if(a[j]>temp)
                a[j+1]=a[j];
            else
                break;
            }
        a[j+1]=temp;
    }
    for(j=0;j<no;j++)
    {
        sum=sum+a[j];
    }
    printf("\n%d",sum);
}