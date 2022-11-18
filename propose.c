#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char name[30],name1[30],ch1,ch2;
int cho1,cho2,cho3,count=0;
void bahar();
printf("\t\t\tTHIS IS THE PROGRAM TO TEST YOU\n");
printf("\n \n");
printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
printf("WRITE DOWN YOUR FIRST NAME\n");
gets(name);
printf("\n");
printf("WRITE DOWN YOUR LAST NAME\n");
gets(name1);
printf("\n");
if(strcmp(name1,"maurya")==0)
{
printf("WELL!!!%s %s FOR CONTINUE WE WILL DISCUSS ABOUT YOUR LIKES DISLIKES\n\n",name,name1);
printf("################################################################################\n");
printf("1-WHICH SPORT DO YOU LIKE MOST\n");
printf("\n \n");
printf("(i)-CRICKET\t \t(ii)-FOOTBALL\n");
printf("type 1 for cricket 2 for football\n");
scanf("%d",&cho1);
printf("\n");
printf("\n");
if(cho1==1)
{
printf("WOW!!! you are awesome %s %s\n ",name,name1);
count++;
}
else
{
printf("hmmmm  :( sorry we can't be freinds\n");
bahar();
}
printf("\n");
printf("\n");
printf("2-DO YOU LIKE MS DHONI\n");
printf("\n");
printf("type y for yes and n for no\n");
fflush(stdin);
ch1=getchar();

if(ch1=='y')
{
printf("\n \n");
printf("OOO....you are doing good\n");
count++;
}
else
{
printf("hmmm....:( we can't be freinds");
bahar();
}
printf("##############################################################");
printf("\n");
printf("3-DO YOU ALSO LIKE KABBADI\n\n");
printf("type y for yes n for no\n");
fflush(stdin);
ch2=getchar();
if(ch2=='y')
{
printf("WOW!!!..yrr you are too good :)\n");
count++;
}
else
{
printf("aree yrr..chlo koi n we will manage\n");
count--;
}
printf("###########################################################################\n");
printf("4-Do you like BJP or CONGRESS\n");
printf("BJP=1\t\tCONGRESS=2\n");
scanf("%d",&cho2);
printf("\n");
printf("\n");
if(cho2==1)
{
printf("WOW!!! you are awesome %s %s\n ",name,name1);
count++;
}
else
{
printf("hmmmm  :( sorry we can't be freinds\n");
bahar();
}
printf("5-What do u prefer Brain or Beauty\n \n");
printf("Brain=1\t\tBeauty=2\n");
scanf("%d",&cho2);
printf("\n");
printf("\n");
if(cho2==1)
{
printf("WOW!!! you are awesome %s %s\n ",name,name1);
count++;
}
else
{
printf("hmmmm  :( sorry we can't be freinds\n");
bahar();
}
printf("your score %d",count);
}


else
{
printf("hto yrr\n");
}











getch();
}
void bahar()
{
char ch1;
printf("well!!!!!!!!!!! we cant be freinds\n");
printf("byeee\n");
printf("plzzz type 'n' :(\n");
fflush(stdin);
ch1=getchar();
if(ch1=='n')
{
exit(0);
}
}

