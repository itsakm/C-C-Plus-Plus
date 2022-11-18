#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
int main()
{
    int del;
    /*FILE *file;
    file=fopen("file.txt","ab");
    getch();
    fclose(file);*/
    rename("file2.txt","file.txt");
    getch();
    remove("file.txt");
    getch();
    
}