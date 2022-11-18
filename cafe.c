#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include<string.h>
//for setting the cursor 
COORD coord ={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
typedef struct 
{
    char name[15],code[15];
    float rate;
    int quantity;
}rec;
rec item;
//declaration of checking function
void c_code(char []);
int check_code(char []);
//declaration of display function
void cursor(int);
void dbill();
void d_mainmenu();
void display_all();
//void display(rec *,int ,int);
void window(int,int ,int,int);
void d_con();
void d_search();
void highlight(int, int);

//declaration of the main menu function
void bill();
void add();
void edit();
void del();
void exit();
void login();

//declaration of the submenu function
void d_code();
void d_rate();
void d_quan();
void d_all();

int main()
{
    system("cls");
   // login();
    d_mainmenu();
    getch();
}
void edit()
{
    int e,ch2,size;//for code exits or not
    FILE *file;
    char x[30],ch1;
    system("cls");
    window(24,9,40,12);
    gotoxy(35,7);
    printf("EDIT ITEMS");
    gotoxy(26,11);
    printf("Enter Item Code To Edit: ");
    fflush(stdin);
    gets(x);
    e=check_code(x);
    if (e==0)
    {
        gotoxy(35,12);
        printf("Code Not Exits");
    }
    else if (e==1)
    {
        file=fopen("record.txt","r+b");
        rewind(file);
        while(fread(&item,sizeof(item),1,file))
        {
            if(strcmp(item.code,x)==0)
            {
                gotoxy(26,12);
                printf("Name:%s",item.name);
                gotoxy(26,13);
                printf("Quantity:%d",item.quantity);
                gotoxy(26,14);
                printf("Rate:%.2f",item.rate);
                gotoxy(26,15);
                printf("Do You Want to Edit this item?(y/n):");
                fflush(file);
                scanf("%c",&ch1);
                if(toupper(ch1)=='Y')
                {
                    gotoxy(26,16);
                    printf("1-Name");
                    printf(" 2-Quantity");
                    printf(" 3-Rate");
                    gotoxy(26,17);
                    printf("Choose from 1,2,3");
                    scanf("  %d",&ch2);
                    switch(ch2)
                    {
                        case 1:
                        gotoxy(30,19);
                        printf(" Enter New Name: ");
                        gotoxy(30,20);
                        scanf("%s",item.name);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;

                    }
                               
                }

            }

        }
        
    }
    fclose(file);
    

}

int check_code( char s[])
{
    FILE *file;
    file=fopen("record.txt","rb");
    while (fread(&item,sizeof(item),1,file))
    {
        if(strcmp(item.code,s)==0)
        {
            return 1;
        }
    }
    fclose(file);
}


void del()
{
    int flag;
    char x[30];
    FILE *file,*file1;
    system("cls");
    window(24,9,35,12);
    gotoxy(35,7);
    printf("DELETE ITEMS");
    gotoxy(26,11);
    printf("Enter Item Code: ");
    gets(x);
    fflush(stdin);
    file1 = fopen("record1.txt", "ab");
    file = fopen("record.txt", "rb");
    rewind(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if (strcmp(item.code, x) != 0)
        {
            fwrite(&item, sizeof(item), 1, file1);
            flag = 0;
        }
    }
    if(flag==0)
    {
    gotoxy(26, 19);
    printf("---Item Deleted---");
    }
    else{
        gotoxy(26, 19);
    printf("---Item Not found---");
    }
    fclose(file1);
    fclose(file);
    remove("record.txt");
    rename("record1.txt", "record.txt");
    if (flag == 1)
    {
        gotoxy(26, 19);
        printf("---Item Does Not Exist---");
        gotoxy(26, 20);
        printf("TRY AGAIN");
    }

    getch();
    d_mainmenu();
}

void d_search()
{
    int i;
    system("cls");
    window(28,7,27,13);
    gotoxy(36,8);
    printf("SEARCH MENU");
    gotoxy(28,9);
    for(i=0;i<=27;i++)
        printf("\xdb");
    cursor(4);
}
void d_quan()
{
    int flag=0,j=0;
    FILE *file;
    file=fopen("record.txt","rb");
    rewind(file);
    fflush(file);
    float lr,up;
    system("cls");
    window(22,7,38,2);
    gotoxy(33,6);
    printf("ITEMS BY QUANTITY");
    gotoxy(24,8);
    printf("Lower Range: ");
    scanf("%f",&lr);
    gotoxy(45,8);
    printf("Upper Range:");
    scanf("%f",&up);
    gotoxy(16,11);
    printf("SN.      CODE         NAME          RATE   QUANTITY");
    while(fread(&item,sizeof(item),1,file))
    {
        if(item.quantity>=lr && item.quantity<=up)
        {
            flag=1;
            gotoxy(16,12+j);
            printf("%d",j+1);
            printf("   %8s",item.code);
            printf("\t%10s",item.name);
            printf("%14.2f",item.rate);
            printf("  %6d",item.quantity);
            j++;
        }
    }
    if (flag==0)
    {
        gotoxy(32,12);
        printf("Items Not found");
    }
    fclose(file);
    getch();
    d_search();  
}
void d_rate()
{
    int flag=0,j=0;
    FILE *file;
    file=fopen("record.txt","rb");
    rewind(file);
    fflush(file);
    float lr,up;
    system("cls");
    window(22,7,38,2);
    gotoxy(37,6);
    printf("ITEMS BY RATE");
    gotoxy(24,8);
    printf("Lower Range: ");
    scanf("%f",&lr);
    gotoxy(45,8);
    printf("Upper Range:");
    scanf("%f",&up);
    gotoxy(16,11);
    printf("SN.      CODE         NAME          RATE   QUANTITY");
    while(fread(&item,sizeof(item),1,file))
    {
        if(item.rate>=lr && item.rate<=up)
        {
            flag=1;
            gotoxy(16,12+j);
            printf("%d",j+1);
            printf("   %8s",item.code);
            printf("\t%10s",item.name);
            printf("%14.2f",item.rate);
            printf("  %6d",item.quantity);
            j++;
        }
    }
    if (flag==0)
    {
        gotoxy(32,12);
        printf("Items Not found");
    }
    fclose(file);
    getch();
    d_search();   
}
void d_code()
{
    int flag=0;
    FILE *file;
    file=fopen("record.txt","rb");
    rewind(file);
    fflush(file);
    char code[15];
    system("cls");
    window(28,7,27,10);
    gotoxy(30,9);
    printf("Enter the code:");
    fflush(stdin);
    gets(code);
    while(fread(&item,sizeof(item),1,file))
    {
        if(strcmp(item.code,code)==0)
        {
            flag=1;
            gotoxy(32,11);
            printf("Name:%s\n",item.name);
            gotoxy(32,13);
            printf("Quantity:%d\n",item.quantity);
            gotoxy(32,15);
            printf("Rate:%f\n",item.rate);
        }
    }
    if(flag==0)
    {
        gotoxy(32,11);
        printf("Item Not found");
    }
    fclose(file);
    getch();
    d_search();

}
void display_all()
{
    FILE *file;
    int i,j=0,flag=0;
    system("cls");
    gotoxy(25,3);
    for(i=1;i<=10;i++)
        printf("\xdb");
    printf("WELCOME TO AVANISH CAFE");
    for(i=1;i<=10;i++)
        printf("\xdb");
    printf("\n\n");
    gotoxy(32,5);
    printf("CAFFETERIA MANAGEMENT SYSTEM");
    gotoxy(39,7);
    printf("ALL ITEMS DETAILS");
    gotoxy(22,9);
    printf("SN.    CODE            NAME           RATE   QUANTITY");
    file= fopen("record.txt","rb");
    rewind(file);
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        flag=1;
        gotoxy(22,11+j);
        printf("%d",j+1);
        printf("\t%8s",item.code);
        printf("\t%10s",item.name);
        printf("%14.2f",item.rate);
        printf("  %6d",item.quantity);
        j++;
    }
    if(flag==0)
    {
        gotoxy(40,11);
        printf("NO Data Found..!!");
    }
    getch();
    fclose(file);
    d_mainmenu();
}

void add()
{
   FILE *file;
   char y[15],x[15];
   system("cls");
   gotoxy(30,13);
   printf("Enter new record(Y/N)?:");
   while(toupper(getche())=='Y')
   {
       system("cls");
       file=fopen("record.txt","ab");
       c_code(y);
       strcpy(item.code,y);
       gotoxy(30,13);
       printf("RATE:");
       scanf("%f",&item.rate);
       gotoxy(30,15);
       printf("QUANTITY:");
       scanf("%d",&item.quantity);
       gotoxy(30,17);
       printf("NAME:");
       scanf("%s",&item.name);
       fseek(file,0,SEEK_END);
       fwrite(&item,sizeof(item),1,file);
       fclose(file);
       gotoxy(30,19);
       printf("Enter new Records(Y/N)?");
   } 
   d_mainmenu();
}

//function to check availability of code
void c_code(char y[])
{
    int flag;
    FILE *file;
    file= fopen("record.txt","rb");
    while(1)
    {
        system("cls");
        window(20,9,40,12);
        gotoxy(34,7);
        printf(" ADD ITEMS ");
        flag=1;
        rewind(file);
        gotoxy(30,11);
        printf("New code: ");
        fflush(stdin);
        gets(y);
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if(strcmp(y,item.code)==0)
            {
                flag=0;
                gotoxy(30,12);
                printf("code already exits");
                gotoxy(30,13);
                printf("Enter again");
                getch();
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}

//for the basic display of the window
void window(int a ,int b,int  c, int d)
{
    int i;
    system("cls");
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        printf("\xdb");
    printf("WELCOME TO AVANISH CAFE");
    for(i=1;i<=10;i++)
        printf("\xdb");
    printf("\n\n");
    gotoxy(27,5);
    printf("CAFFETERIA MANAGEMENT SYSTEM");
    gotoxy(a,b);
    for(i=0;i<=c;i++)
    {
        gotoxy(a+i,b);
        printf("\xdb");
    }
    gotoxy(a,b);
    for(i=0;i<=d;i++)
    {
        gotoxy(a,b+i);
        printf("\xdb");
    }
    gotoxy(a,b+d);
    for(i=0;i<=c;i++)
    {
        gotoxy(a+i,b+d);
        printf("\xdb");
    }

    gotoxy(a+c,b);
    for(i=0;i<=d;i++)
    {
        gotoxy(a+c,b+i);
        printf("\xdb");
    }
}
//login page 
void login()
{
    int a=0;
    char uname[10],passwd[10];
    char c=' ';
    char user[10]="user";
    char pass[10]="pass";
    int i,j;
    do
    {
        gotoxy(20,3);
        for(i=1;i<=10;i++)
            printf("\xdb");
        printf("  LOGIN FORM  ");
        for(i=1;i<=10;i++)
            printf("\xdb");
        gotoxy(26,5);
        printf("USER NAME:");
        scanf("%s",&uname);
        gotoxy(26.8,6);
        printf("PASSWORD:");
        j=0;
        while(j<10)
        {
            passwd[j]=getch();
             c=passwd[j];
                if(c==13) break;
                else printf("#");
                j++;
        }
            passwd[j]='\0';
            j=0;
            if(strcmp(uname,"user")==0 && strcmp(passwd,"pass")==0)
            {
                gotoxy(26,8);
                printf("LOGIN SUCCESSFUL ");
                gotoxy(26,9);
                printf("press any key to continue");
                getch();
                break;
            }
            else
            {
                gotoxy(26,8);
                printf("USER NAME AND PASSWORD INCORRECT!!!");
                a++;
                getch();
                system("cls");
            }
            
        }
    while(a<=2);
    if(a>=2)
    {
        gotoxy(26,5);
        printf("SORRY YOU HAVE ENTERED 3 TIME INCORRECT PASSWORD");
        gotoxy(26,6);
        printf("YOU NEED TO RESTART THE PROGRAM");
        getch();
        exit(1);
    }
}
//highlight
void highlight(int no,int count)
{
    if(no==4)
    {
        gotoxy(34,11);
        printf(" By code   ");
        gotoxy(34,13);
        printf(" By Rate   ");
        gotoxy(34,15);
        printf(" By Quantity   ");
        gotoxy(34,17);
        printf(" Back to main menu");
        switch (count)
        {
            case 1:
            gotoxy(34,11);
            printf(" -By code    ");
            break;
            case 2:
            gotoxy(34,13);
            printf(" -By Rate    ");
            break;
            case 3:
            gotoxy(34,15);
            printf(" -By Quantity    ");
            break;
            case 4:
            gotoxy(34,17);
            printf(" -Back to main menu");
            break;
        }
    }
    if(no==7)
    {
        gotoxy(37,15);
        printf(" Caluclate Bill   ");
        gotoxy(37,16);
        printf(" Add ITEMS   ");
        gotoxy(37,17);
        printf(" Edit ITEMS   ");
        gotoxy(37,18);
        printf(" Display ITEMS   ");
        gotoxy(37,19);
        printf(" Search   ");
        gotoxy(37,20);
        printf(" Delete ITEMS   ");
        gotoxy(37,21);
        printf(" Exit   ");
        switch (count)
        {
        case 1:
        gotoxy(37,15);
        printf("- Calculate Bill");
        break;
        case 2:
        gotoxy(37,16);
        printf(" -Add ITEMS   ");
        break;
        case 3:
        gotoxy(37,17);
        printf(" -Edit ITEMS   ");
        break;
        case 4:
        gotoxy(37,18);
        printf(" -Display ITEMS ");
        break;
        case 5:
        gotoxy(37,19);
        printf(" -Search  ");
        break;
        case 6:
        gotoxy(37,20);
        printf(" -Delete ITEMS ");
        break;
        case 7:
        gotoxy(37,21);
        printf(" -Exit   ");
        break;
        }

    }
}
//for moving the cursor
void cursor(int no)
{
    int count=1;
    char ch='0';
    gotoxy(47,15);
    while(1)
    {
        switch(ch)
        {
            case 80:
                count++;
                if(count==no+1) count=1;
                break;
            case 72:
                count--;
                if(count==0) count=no;
                break;
        }
        highlight(no,count);
        ch=getch();
        if(ch=='\r')
        {
            if(no==7)
            {
                if(count==1) printf("count1\n");// bill();
                else if(count==2) add();
                else if(count==3) edit();
                else if(count==4) display_all();
                else if(count==5) d_search();
                else if(count==6) del();
                else exit(0);
            }
            if(no==4)
            {
                if(count==1) d_code();
                else if(count==2) d_rate();
                else if(count==3) d_quan();
                else d_mainmenu();
            }
        }
    }

}

void d_mainmenu()
{
    const char *menu[]={"Calculate bill","Order Items","Edit Order","Display Order","Search","Delete Orders","Exit"};
    char ch;
    int i,j=0;
    system("cls");
    window(30,13,25,10);
    gotoxy(30,10);
    for(j=0;j<=25;j++)
        printf("\xdb");
    gotoxy(30,12);
    for(j=0;j<=25;j++)
        printf("\xdb");
    gotoxy(30,11);
    printf("\xdb");
    gotoxy(55,11);
    printf("\xdb");
    gotoxy(39,11);
    printf("CAFE MENU");
    for(i=0;i<=6;i++)
    {
        gotoxy(37,13+i+2);
        printf("%s",menu[i]);
        //printf("\n\n");
    }
    cursor(7);
}


