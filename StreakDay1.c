#include<stdio.h>
#include<conio.h>
int main()
{
    int i=0,j=0,num=0;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        int num2=i;
        int n=6;
        for(j=num;j>=i;j--)
        {
            if(i%2!=0)
            {
                if(num2==i)
                {
                    printf("%d ",i);
                    num2=num2+n;
                    --n;
                }
                 /* else if(num2!=i && n<0)
                {
                    n=1;
                    num2=num2-n;
                    printf("%d ",num2);
                    ++n;
                    printf("num=%d n=%d ",num2,n);
                } */ 
                else if(num2!=i && n>=0 && n<=5)
                {
                    printf("%d ",num2);
                    num2=num2+n;
                    --n;  
                    printf("num=%d n=%d ",num2,n); 
                }      
            }
            else if(i%2==0)
            {
                if(num2==i)
                {
                    printf("%d ",i);
                    num2=num2+n;
                    ++n;
                }
                else
                {    
                    printf("%d ",num2);
                    num2=num2+n;
                    ++n;  
                    printf("num=%d n=%d ",num2,n);
                }
               
            }
            
        }
        printf("\n");
    }

}