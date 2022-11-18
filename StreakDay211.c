#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* substring(char*, int, int);
int main()
{
    int n=0,subI[1000]={0},k=0;
    char ch[1000],*sub[1000],temp[1000];
    scanf("%d",&n);
    scanf("%s",ch);
    for(int i=0;i<strlen(ch)-1;i++)
    {
        printf("ch[%d]=%c ch[%d]=%c",i,ch[i],i+1,ch[i+1]);
        if(ch[i]<ch[i+1])
        {
            char *p,*p1;
            p=substring(ch,i+1,2);
            printf("p=%s  ",p);
            sub[k]=malloc(2);
            strcpy(sub[k],p);
            for(int j=(i+3);j<strlen(ch);j++)
            {
                p1=substring(ch,j,2);
                printf("p1=%s  ",p1);
                if(strcmp(p,p1)==0)
                {
                    subI[k]++;
                }
            } 
            printf("sub[%d]=%s  ",k,sub[k]);
            printf("subI[%d]=%d\n",k,subI[k]);
            ++k;
        }      
        printf("\n"); 
    }
    printf("k=%d",k);
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
            count++;
        }
    }
    if(count==1)
    {
        printf("  %s  ",sub[loc]);
    }
    else if(count>1)
    {
        for (int i = 0; i < k; ++i) 
            {
                for (int j = i + 1; j < k; ++j)
                    {
                        if (strcmp(sub[i], sub[j]) > 0) 
                            {
                                strcpy(temp, sub[i]);
                                strcpy(sub[i], sub[j]);
                                strcpy(sub[j], temp);
                            }
                    }
            }
            printf("  %s  ",sub[0]);
    }
    for(int i=0;i<k;i++)
    {
       printf("  %s  ",sub[i]); 
    }
    printf("count=%d",count);//COUUNT KI VALUE 1 HAI TO SHI HAI
    printf("max=%d",max);
    printf("loc=%d ",loc);
    
}
char *substring(char *string, int position, int length)
{
   char *p;
   int c;
 
   p = malloc(length+1);
   
   if (p == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0; c < length; c++)
   {
      *(p+c) = *(string+position-1);     
      string++;  
   }
 
   *(p+c) = '\0';
   printf("p[0]=%c  p[1]=%c  ",*p,*(p+1));
       return p;
   
   
 
   
}