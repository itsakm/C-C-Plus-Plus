#include<stdio.h>
int main()
{
    char ch,ch1;
    char *s="Sanfoundry.com\0" "training classes";
    
    signed char chr;
    chr=128;
    ch=(char)(1);
    ch1=(char)(53);
    printf("%c",ch);
    printf("%c",ch1);
    printf("%d",chr);
    printf("c programming %s %s","class by \n %s sanfoundary","wow");
    printf("%s",*(&s));
}