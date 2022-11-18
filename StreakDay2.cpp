#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* substring(char*, int, int);
int main()
{
    int n=0,subI[1000]={0},k=0,m=0;
    char *ch,*sub[1000],temp[100],*sub1[1000];
    scanf("%d",&n);
    ch=(char*)malloc(sizeof(char)*n);
    scanf("%s",ch);
    for(int i=0;i<strlen(ch)-1;i++)
    {
        if(ch[i]<ch[i+1])
        {
            char *p,*p1;
            p=substring(ch,i+1,2);
            sub[k]=(char*)malloc(2);
            strcpy(sub[k],p);
            for(int j=(i+3);j<strlen(ch);j++)
            {
                p1=substring(ch,j,2);
                if(strcmp(p,p1)==0)
                {
                    subI[k]++;
                }
            } 
            ++k;
        }      
    }
    int loc=0;
    int max=subI[0];
    for(int i=1;i<k;i++)
    {
        if(subI[i]>subI[loc])
        {
            max=subI[i];
            loc=i;
        }
    }
    int count=0;
    for(int i=0;i<k;i++)
    {
        if(subI[i]==max)
        {
            sub1[m]=(char*)malloc(2);
            strcpy(sub1[m],sub[i]);
            count++;
            m++;
        }
    }
    if(count==1)
    {
        printf("%s",sub[loc]);
    }
    else if(count>1)
    {
        for (int i = 0; i < m; ++i) 
            {
                for (int j = i + 1; j < m; ++j)
                    {
                        if (strcmp(sub[i], sub[j]) > 0) 
                            {
                                strcpy(temp, sub1[i]);
                                strcpy(sub1[i], sub1[j]);
                                strcpy(sub1[j], temp);
                            }
                    }
            }
            printf("%s",sub1[0]);
    }   
}
char *substring(char *string, int position, int length)
{
   char *p;
   int c;
 
   p = (char*)malloc(length+1);
   
   if (p == NULL)
   {
      exit(1);
   }
 
   for (c = 0; c < length; c++)
   {
      *(p+c) = *(string+position-1);     
      string++;  
   }
 
   *(p+c) = '\0';
       return p;  
}