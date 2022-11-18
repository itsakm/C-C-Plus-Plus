#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,sum=0,diff=0;
    char str[100000];
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        for(j=i+1;j<strlen(str);j++)
        {
            if(str[i]==str[j])
            {  
                diff=((i+1)-(j+1))<0?-((i+1)-(j+1)):((i+1)-(j+1));
                sum=sum+diff;
            }
        }
    }
    printf("%d",sum);
}