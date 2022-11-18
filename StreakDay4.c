#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num=0,day=0,max=0;
    scanf("%d",&num);
    int income[num],total[num];
    for(int i=1;i<=num;i++)
    {
        scanf("%d",&income[i]);
    }
    total[0]=0;
    for(int i=1;i<=num;i++)
    {
        total[i]=total[i-1]+income[i];  
        if(total[i]>max)
        {
            max=total[i];
            day=i;
        }
    }
    if(total[num]<=0)
    {
        printf("%d",0);
    }
    else if(total[num]>0)
    {
        printf("%d",day);
    }
    return 0;
}
