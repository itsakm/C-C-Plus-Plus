#include<stdio.h>
#include<conio.h>
int main()
{
    int arr1[10],arr2[10],arr3[10];
    int i,j,k,l,m,a=1;
    for(i=1;i<=10;i++)
    {
        arr1[i]=i;
    }
    for(j=1;j<=10;j++)
    {
        arr2[j]=j;
    }
    for(k=1;k<=10;k++)
    {
        arr3[k]=arr1[k];
    }
    for(l=10+a;l<=20;l++)
    {
        arr3[l]=arr2[a];
        a++;
    }
    for(m=1;m<=20;m++)
    {
        printf("%d\n",arr3[m]);
    }
}