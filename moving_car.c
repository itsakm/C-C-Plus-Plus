#include<stdio.h>
#include<conio.h>
#include<window.h>
//#include<dos>
//#include<graphics.h>
void main()
{
int i,j=0,gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(25,240,"press any key to view the moving car");
getch();
setviewport(0,0,639,440,1);
for(i=0;i<=420;i=i+10,j++)
{
rectangle(50+i,275,150+i,400);
rectangle(150+i,350,200+i,400);
circle(75+i,410,10);
circle(175+i,410,10);
setcolor(j);
delay(100);
if(i==420)
break;
clearviewport();
}
getch();
cleardevice();
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(100,200,"enjoyed");
delay(5000);
closegraph();
}

