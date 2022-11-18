#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
COORD coord ={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void anim(const char *s)
{
    int i,j;
    i=strlen(s);
    char ch[i+1];
    strcpy(ch,s);
    for(j=0;j<i;j++)
    {
    printf("%c",ch[j]);
    usleep(100);
    }
}
void vertical(int x,int y,int l)
{
    gotoxy(x,y);
    for(int i=0;i<l;i++)
    {
        gotoxy(x,y+i);
        anim("\xdb");
        gotoxy(x+1,y+i);
        anim("\xdb");
    }

}
void horizontal(int x,int y,int l)
{
    gotoxy(x,y);
    for(int i=0;i<l;i++)
    {
        gotoxy(x+i,y);
        anim("\xdb");
        gotoxy(x+i,y+1);
        anim("\xdb");
    }
}
void horizontal1(int x,int y,int l)
{
    gotoxy(x,y);
    for(int i=0;i<l;i++)
    {
        gotoxy(x+i,y);
        anim("\xdb");
        
    }
}
void window(int a,int b,int c ,int d)
{
    int i;
    gotoxy(a,b);
    for(i=0;i<=c;i++)
    {
        gotoxy(a+i,b);
        anim("\xdb");
    }
    gotoxy(a,b);
    for(i=0;i<=d;i++)
    {
        gotoxy(a,b+i);
        anim("\xdb");
    }
    gotoxy(a,b+d);
    for(i=0;i<=c;i++)
    {
        gotoxy(a+i,b+d);
        anim("\xdb");
    }

    gotoxy(a+c,b);
    for(i=0;i<=d;i++)
    {
        gotoxy(a+c,b+i);
        anim("\xdb");
    }
}

int main()
{
    system("cls");
    getch();
    
    //H
    vertical(25,10,10);
    horizontal(25,14,10);
    vertical(35,10,10);
   //A
    vertical(39,10,10);
    horizontal(39,10,10);
    vertical(49,10,10);
    horizontal(39,14,10);
    //P
    vertical(53,10,10);
    horizontal(53,10,10);
    vertical(63,10,5);
    horizontal(53,14,11);

    //P
    vertical(67,10,10);
    horizontal(67,10,10);
    vertical(77,10,5);
    horizontal(67,14,11);
    

    //Y
    vertical(81,10,5);
    horizontal(81,14,10);
    vertical(91,10,5);
    vertical(86,14,6);

    //E
    vertical(57,24,10);
    horizontal(57,24,10);
    horizontal(57,34,10);
    horizontal(57,29,10);

    //N
    vertical(71,24,12);
    vertical(81,24,12);
    gotoxy(71,24);
    for(int i=0;i<12;i++)
    {
        gotoxy(71+i,24+i);
        anim("\xdb");
        gotoxy(71+i+1,24+i+1);
        anim("\xdb");
    }

    //G
    vertical(85,24,10);
    horizontal(85,24,10);
    horizontal(85,34,10);
    vertical(95,29,7);
    horizontal(92,29,3);
    
    //I
    vertical(99,24,12);

    //N
    vertical(103,24,12);
    vertical(113,24,12);
    gotoxy(102,24);
    for(int i=0;i<12;i++)
    {
        gotoxy(103+i,24+i);
        anim("\xdb");
        gotoxy(103+i+1,24+i+1);
        anim("\xdb");
    }

    //E
    vertical(117,24,10);
    horizontal(117,24,10);
    horizontal(117,34,10);
    horizontal(117,29,10);

    //E
    vertical(131,24,10);
    horizontal(131,24,10);
    horizontal(131,34,10);
    horizontal(131,29,10);

    //R
    vertical(145,24,12);
    horizontal(145,24,10);
    horizontal(145,28,10);
    vertical(155,24,5);
    gotoxy(145,28);
    for(int i=0;i<8;i++)
    {
        gotoxy(145+i,28+i);
        anim("\xdb");
    }


    //S
    vertical(159,24,5);
    horizontal(159,24,12);
    horizontal(159,28,10);
    vertical(169,28,7);
    horizontal(159,34,10);

    //D
    vertical(145,38,10);
    horizontal(144,38,11);
    vertical(155,38,10);
    horizontal(144,48,13);

    //A
    vertical(159,38,12);
    horizontal(159,38,10);
    vertical(169,38,12);
    horizontal(159,42,10);

    //Y
    vertical(173,38,5);
    horizontal(173,42,10);
    vertical(183,38,5);
    vertical(178,42,8);
    getch();
    system("cls");
    window(65,10,20,10);
    window(70,12,2,2);
    window(78,12,2,2);
    window(75,14,1,1);
    window(73,17,6,2);
    vertical(74,8,2);
    horizontal(68,20,15);
    horizontal(71,21,10);
    window(67,22,16,7);
    vertical(69,29,5);
     vertical(78,29,5);
     horizontal1(59,24,8);
    horizontal1(83,24,8);
    getch();
    

}