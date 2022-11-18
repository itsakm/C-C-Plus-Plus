#include <stdio.h>
#include <string.h>
#include <math.h>
#include<conio.h>

#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n=0,evenCounter=0;
    scanf("%d",&n);
    int d[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
        if(d[i]%2==0)
        {
            evenCounter++;
        }
    }
    if(evenCounter==0)
    {
        printf("%d",-1);
    }
    else if(evenCounter==1)
    {
        int d1[n-1];
        int even=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]%2==0)
            {
                even=d[i];
            }
            else
            {
                
                d1[k]=d[i];
                k++;
            }
        }
        for (int i = 0; i<k; ++i) 
        {
            for (int j = i + 1; j< k; ++j) 
            {
                if (d1[i] < d1[j]) 
                {
                    int a=0;
                    a = d1[i];
                    d1[i] = d1[j];
                    d1[j] = a;
                }
            }
        }
        int result=0;
        for(int i=0;i<k;i++)
        {
            printf("%d",d1[i]);
        }
        printf("%d",even);
        
    }
    else if(evenCounter>1)
    {
        int evenarr[n],e=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]%2==0)
            {
                evenarr[e]=d[i];
                e++;
            }
        }
        int mineven=evenarr[0];
        for(int i=1; i<e; i++)
        {
            if(mineven>evenarr[i])
                mineven=evenarr[i];          
        }
        int d1[n-1];
        int k=0;
        int even=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]==mineven)
            {
                even=d[i];
            }
            else
            {
                
                d1[k]=d[i];
                k++;
            }
        }
        for (int i = 0; i<k; ++i) 
        {
            for (int j = i + 1; j< k; ++j) 
            {
                if (d1[i] < d1[j]) 
                {
                    int a=0;
                    a = d1[i];
                    d1[i] = d1[j];
                    d1[j] = a;
                }
            }
        }
        int result=0;
        for(int i=0;i<k;i++)
        {
            printf("%d",d1[i]);
        }
        printf("%d",even);
    }
    
getch();
    return 0;
}
