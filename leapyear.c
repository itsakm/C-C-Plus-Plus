#include<stdio.h>
#include<conio.h>
void main()
{
    int yr;
    printf("enter a year\n");
    scanf("%d",&yr);
    if(yr%100==0)
    {
        if(yr%400==0)
            printf("leap yeaer\n");
        else
            printf("not a leap year\n");
    }
    else
    {
        if(yr%4==0)
            printf("leap year\n");
        else
            printf("not a leap year\n");
    }
    
    getch();
    
}