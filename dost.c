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
    char name[30],status[20];
    int ch[20];
    int total;
}item;
item mitra; 
//declaration of all funcion
void face();//very first interface for guest and owner
void question();
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();
void question12();
void question13();
void question14();
void question15();

void owner();//owner interface
void window(int ,int ,int ,int);
void read();
void cursor(int);
void highlight(int, int);
void score(); //for displaying the  individual score after questions
void indi_score();//for displaying the individual score by owner
void homepage();
void loading();
//for print in animation
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

int main()
{
    face();
    system("cls");
}
void face()
{
    int ch,flag=0;
        system("cls");
        gotoxy(20,3);
        anim("HELLO GUEST PLEASE PRESS 1  :-)");
        scanf("%d",&ch);
        gotoxy(20,5);
        anim("Loading....Please wait!!");
        gotoxy(21,7);
        loading();
        if(ch==1)
        {
            homepage();
        }
        else if(ch==2)
        {
            owner();
        }
        else
        {
            gotoxy(20,4);
            anim("Kindly Press '1' only....!!");
            getch();
            face();
        }   
}

void indi_score()
{
    char x[30]="";
    char new[30];
    int j=0,flag=0;
    FILE *file;
    file=fopen("dosti.txt","rb");
    rewind(file);
    fflush(file);
    system("cls");
    window(20,3,44,4);
    gotoxy(22,4);
    printf("Boss Please Enter Your Freinds Name..\n");
    gotoxy(22,5);
    fflush(stdin);
    gets(new);
    x[j]=toupper(new[0]);
    j++;
    while(new[j] !='\0')
    {
        if(isspace(new[j]))
        {
            x[j]=new[j];
            x[j+1]=toupper(new[j+1]);
            j+=2;
        }
        else
        {
            x[j]=new[j];
            j++;
        }    
    }
    while(fread(&mitra,sizeof(mitra),1,file))
    {
        if((strcmp(mitra.name,x)==0))
        {
            flag=1;
            score();
            system("cls");
        }   
    }
    if(flag==0)
    {
        gotoxy(22,6);
        printf("Not Found Boss Please Enter his/her SurName");
        getch();
    }
    fclose(file);
}
void read()
{
    int i,j=0;
    FILE *file;
    file=fopen("dosti.txt","rb");
    rewind(file);
    fflush(file);
    system("cls");
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" All Freinds Total ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(16,4);
    printf("SN.   \t   Name\t\t  Total\t Right\t Wrong");
    while (fread(&mitra,sizeof(mitra),1,file))
    {
        gotoxy(14,5+j);
        printf("%3d",j+1);
        printf("  %17s",mitra.name);
        printf("\t   15");
        printf("\t   %d",mitra.total);
        printf("\t  %d",(15-mitra.total));
        j++;
    }
    fclose(file);
    gotoxy(16,(5+j+1));
    anim("Press Any Key for Back...");
    getch();
    owner();
    
}
void question()
{
    FILE *file;
    int i,j=0;
    char new[30];
    system("cls");
    int ch;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" HELLO GUEST ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    window(15,5,40,4);
    gotoxy(22,6);
    anim("Please Enter Your Name...");
    gotoxy(24,7);
    fflush(stdin);
    gets(new);
    mitra.name[j]=toupper(new[0]);
    j++;
    while(new[j] !='\0')
    {
        if(isspace(new[j]))
        {
            mitra.name[j]=new[j];
            mitra.name[j+1]=toupper(new[j+1]);
            j+=2;
        }
        else
        {
            mitra.name[j]=new[j];
            j++;
        }    
    }
    file=fopen("dosti.txt","ab");
    gotoxy(23,8);
    anim("Ooo..Nice Name :-D");
    getch();
    system("cls");
    question1();
    system("cls");
    question2();
    system("cls");
    question3();
    system("cls");
    question4();
    system("cls");
    question5();
    system("cls");
    question6();
    system("cls");
    question7();
    system("cls");
    question8();
    system("cls");
    question9();
    system("cls");
    question10();
    system("cls");
    question11();
    system("cls");
    question12();
    system("cls");
    question13();
    system("cls");
    question14();
    system("cls");
    question15();
    system("cls");
    fseek(file,0,SEEK_END);
    fwrite(&mitra,sizeof(mitra),1,file);
    fclose(file);
    score();
}

void score()
{
    int i;
    system("cls");
    gotoxy(45,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" YOUR PERFORMANCE ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(58,4);
    printf("%s",mitra.name);
    gotoxy(20,5);
    printf("              Questions                         Options               Choice       Answer");
    gotoxy(20,6);
    printf("Q1.");
    anim("Which sport Avanish likes...");
    anim("\t  (1.)Football\t (2.)Cricket");
    printf("\t    %d",mitra.ch[1]);
    printf("\t        %c",mitra.status[1]);
    gotoxy(20,8);
    printf("Q2.");
    anim("What do you prefer....");
    
    anim("\t \t (1.)-Money\t (2.)-Love");
    printf("\t    %d",mitra.ch[2]);
    printf("\t        %c",mitra.status[2]);
    gotoxy(20,10);
    printf("Q3.");
    anim("What do you prefer....");
    anim("\t\t(1.)-Bollywood\t (2.)-Hollywood");
    printf("\t    %d",mitra.ch[3]);
    printf("\t        %c",mitra.status[3]);
    gotoxy(20,12);
    printf("Q4.");
    anim("Okk.. Now say about Java or Python.");
    anim("(1.)-Java\t (2.)-Python");
    printf("\t    %d",mitra.ch[4]);
    printf("\t        %c",mitra.status[4]);
    gotoxy(20,14);
    printf("Q5.");
    anim("So..Have you ever watched Marvel ");
    anim("(1.)-Yeah\t (2.)-No );");
    printf("\t    %d",mitra.ch[5]);
    printf("\t        %c",mitra.status[5]);
    gotoxy(20,15);
    anim("  Avengers  Movie..?");
    gotoxy(20,17);
    printf("Q6.");
    anim("Do U really appreciate and be Happy");
    anim("(1.)-No\t (2.)-yosss );");
    printf("\t    %d",mitra.ch[6]);
    printf("\t        %c",mitra.status[6]);
    gotoxy(20,18);
    anim(" on my owner Success?");
    gotoxy(20,20);
    printf("Q7.");
    anim("Suppose u have to choose one...");
    anim("(1.)-My OWNER\t (2.)-OtherStupid");
    printf("    %d",mitra.ch[7]);
    printf("\t        %c",mitra.status[7]);
    gotoxy(20,22);
    printf("Q8.");
    anim("Do u think he sud stop Abusive Lang.?");
    anim("(1.)-No\t (2.)-Yossssss\t");
    printf("    %d",mitra.ch[8]);
    printf("\t        %c",mitra.status[8]);
    gotoxy(20,24);
    printf("Q9.");
    anim("Do u like Space Exploration..?\t");
    anim("(1.)-No\t (2.)-Yossssss\t");
    printf("\t      %d",mitra.ch[9]);
    printf("\t        %c",mitra.status[9]);
    gotoxy(20,26);
    printf("Q10.");
    anim("What Matters to u..?\t\t");
    anim("(1.)-Lob\t (2.)-Firaandship");
    printf("    %d",mitra.ch[10]);
    printf("\t        %c",mitra.status[10]);
    gotoxy(20,28);
    printf("Q11.");
    anim("Are u crazy for Music and Food?\t");
    anim("(1.)-Yossss\t (2.)-Nohiii");
    printf("       %d",mitra.ch[11]);
    printf("\t     %c",mitra.status[11]);
    gotoxy(20,30);
    printf("Q12.");
    anim("Where would you like to Go..\t");
    anim("(1.)-KedarNath ji\t (2.)-Goa");
    printf("       %d",mitra.ch[12]);
    printf("\t     %c",mitra.status[12]);
    gotoxy(20,32);
    printf("Q13.");
    anim("Where does he prefer to go...\t");
    anim("(1.)-Beaches\t (2.)-Hills");
    printf("       %d",mitra.ch[13]);
    printf("\t     %c",mitra.status[13]);
    gotoxy(20,34);
    printf("Q14.");
    anim("Do you know what he like from these..\t");
    anim("(1.)-Chole Bhature & Lassi\t (2.)-Pizza & Cold Drink");
    printf("       %d",mitra.ch[14]);
    printf("\t     %c",mitra.status[14]);
    gotoxy(20,36);
    printf("Q15.");
    anim("According to you which one is best..\t");
    anim("(1.)-Android\t (2.)-iOs");
    printf("       %d",mitra.ch[15]);
    printf("\t     %c",mitra.status[15]);
    getch();
}

void question15()
{
    int ch,i,Q=15;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 15 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("According to you which one is best..");
    gotoxy(20,8);
    anim("(1.)-Android\t (2.)-iOs");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("You have the good test of Smart Phones :D");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("You might be a rich person...but stupid  :)");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question15();
    }
}


void question14()
{
    int ch,i,Q=14;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 14 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Do you know what he like from these ");
    gotoxy(20,8);
    anim("(1.)-Chole Bhature & Lassi\t (2.)-Pizza & Cold Drink");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("Oho Desi Indian...i liked that :D");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Kabhi kha ke dekho deshi cheeze...");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question14();
    }
}




void question13()
{
    int ch,i,Q=13;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 13 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Where does he prefer to go...");
    gotoxy(20,8);
    anim("(1.)-Beaches\t (2.)-Hills");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("Mountains have the real beauty of earth...");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("Beaches are also good...but he prefer Mountains");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question13();
    }
}



void question12()
{
    int ch,i,Q=12;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 12 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Where would you like to Go..");
    gotoxy(20,8);
    anim("(1.)-KedarNath ji\t (2.)-Goa");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("Jai Bhole...");
        mitra.status[Q]='T';
        mitra.total++;
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Goa kyu.. India chorkr england chle jao");
        mitra.status[Q]='F';
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question12();
    }
}





void question11()
{
    int ch,i,Q=11;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 11 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Are u crazy for Music and Food?");
    gotoxy(20,8);
    anim("(1.)-Yossss\t (2.)-Nohiii");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("Lob..hihihi");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Mar jao ek ehsan kro...");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question11();
    }
}


void question10()
{
    int ch,i,Q=10;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 10 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("What Matters to u..?");
    gotoxy(20,8);
    anim("(1.)-Lob\t (2.)-Firanship");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("-Firaandship is best thing...be Mah Frnd.. hihihi");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("gud..katega sbka katega");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question10();
    }
}


void question9()
{
    int ch,i,Q=9;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 9 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Do u like Space Exploration..?");
    gotoxy(20,8);
    anim("(1.)-No\t (2.)-Yossss");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("-Yeah..would u like to go Mars wid his hahha");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("Dharti pe pde rho bus,,,");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question9();
    }
}


void question8()
{
    int ch,i,Q=8;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 8 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Do u think he sud stop Abusive Lang.?");
    gotoxy(20,8);
    anim("(1.)-No\t (2.)-Yossss");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("He will Consider it..Thanks");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("Aur Kya bc..Gali mst cheez hai.");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question8();
    }
}


void question7()
{
    int ch,i,Q=7;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 7 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Suppose u have to choose one...");
    gotoxy(20,8);
    anim("(1.)-My OWNER\t (2.)-OtherStupid );");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("Your Choice is M@@l...");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("People choose what they are..STUPID");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question7();
    }
}


void question6()
{
    int ch,i,Q=6;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 6 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("Do U really appreciate and be Happy on my owner Success?");
    gotoxy(20,8);
    anim("(1.)-No Not at all\t (2.)-yosss );");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("Thanks a lot sir/ma'am..he is hardworker..");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("I have to kill u..jst useless person  >:(");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question6();
    }
}

void question5()
{
    int ch,i,Q=5;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 5 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,58,6);
    gotoxy(22,7);
    anim("So..Have you ever watched Marvel Avengers Movie..?");
    gotoxy(20,8);
    anim("(1.)-Yeah\t (2.)-No );");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("WoW...Man I would like to watch End game wid u..hehe");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Basically you are wasting your life  >:(");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question5();
    }

}

void question4()
{
    int ch,i,Q=4;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 4 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,50,6);
    gotoxy(22,7);
    anim("Okk.. Now say about Java or Python.");
    gotoxy(20,8);
    anim("(1.)-Java\t (2.)-Python");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("I think you are a real programmer..hihihi");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Jake uski kamian pdo..>:(");
        mitra.status[Q]='F';
        mitra.ch[Q]=ch;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question4();
    }
}

void question3()
{
    int ch,i,Q=3;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 3 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,46,6);
    gotoxy(22,7);
    anim("What do you prefer....");
    gotoxy(20,8);
    anim("(1.)-Bollywood\t (2.)-Hollywood");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("Osm Osm Osm...mja aa gio bhau..haha  '_'");
        mitra.status[Q]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("Nepotizm Bollywood :-(");
        mitra.status[Q]='F';
        printf("%d\n",mitra.total );
        mitra.ch[Q]=ch;
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question3();
    }
}


void question2()
{
    int ch,i,Q=2;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 2 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,40,6);
    gotoxy(22,7);
    anim("What do you prefer....");
    gotoxy(20,8);
    anim("(1.)-Money\t (2.)-Love");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==1)
    {
        gotoxy(20,10);
        anim("Ohhhh...Nice Answer..u r gud  '_'");
        mitra.status[2]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[2]=1;
        getch();
    }
    else if(ch==2)
    {
        gotoxy(20,10);
        anim("Ummm..Bad choice.. :-(");
        mitra.status[2]='F';
        printf("%d\n",mitra.total );
        mitra.ch[2]=2;
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question2();
    }
}
void question1()
{
    int ch,i;
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim(" QUESTION 1 ");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(25,5);
    for(i=1;i<=5;i++)
        anim("\xdb");
    printf(" %s ",mitra.name);
    for(i=1;i<=5;i++)
        anim("\xdb");
    window(15,6,40,6);
    gotoxy(22,7);
    anim("Which sport Avanish likes...");
    gotoxy(20,8);
    anim("(1.)-Football\t (2.)-Cricket");
    gotoxy(20,9);
    scanf("%d",&ch);
    if(ch==2)
    {
        gotoxy(20,10);
        anim("Ohhhh...Nice Answer..u r gud  '_'");
        mitra.status[1]='T';
        mitra.total++;
        printf("%d\n",mitra.total );
        mitra.ch[1]=2;
        getch();
    }
    else if(ch==1)
    {
        gotoxy(20,10);
        anim("Ummm..Bad choice.. :-(");
        mitra.status[1]='F';
        mitra.ch[1]=1;
        printf("%d\n",mitra.total );
        getch();
    }
    else
    {
        gotoxy(20,10);
        anim("Kindly Enter only '1' or '2'...!! ");
        getch();
        system("cls");
        question1();
    }
}
void owner()
{
    int i;
    system("cls");
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        printf("\xdb");
    printf(" WELCOME BOSS ");
    for(i=1;i<=10;i++)
        printf("\xdb");
    gotoxy(20,5);
    printf("YOU HAVE FOUND ME...YOU ARE A GENIOUS  :D");
    gotoxy(23,7);
    printf("SO...WHAT DO YOU WANT TO DO..!");
    window(27,10,24,10);//d length c width
    cursor(4);
}

void cursor(int n)
{
    int count=1;
    char ch='0';
    gotoxy(31,12);
    while(1)
    {
        switch(ch)
        {
            case 80:
                count++;
                if(count==n+1) count=1;
                break;
            case 72:
                count--;
                if(count==0) count=n;
        }
        highlight(n,count);
        ch=getch();
        if(ch=='\r')
        {
           if(count==1) read();
           else if(count==2)
           {
                indi_score();
                owner();
           }
           else if(count==3)
           {
               main();
               system("cls");
               owner();
           }
           else exit(0);
        }
    }   
}
void highlight(int n,int count)
{
    gotoxy(31,12);
    printf("  All Score  ");
    gotoxy(31,14);
    printf("  Score By Name  ");
    gotoxy(31,16);
    printf("  Another Test  ");
    gotoxy(31,18);
    printf("  Exit  ");
    switch(count)
    {
        case 1:
            gotoxy(31,12);
            printf("  -All Score  ");
            break;
        case 2:
            gotoxy(31,14);
            printf("  -Score By Name  ");
            break;
        case 3:
            gotoxy(31,16);
            printf("  -Anothet Test  ");
            break;
        case 4:
            gotoxy(31,18);
            printf("  -Exit  ");
            break;
    }
}


void window(int a,int b,int c ,int d)
{
    int i;
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
void homepage()
{
    int i;
    system("cls");
    gotoxy(20,3);
    for(i=1;i<=10;i++)
        anim("\xdb");
    anim("WELCOME GUEST");
    for(i=1;i<=10;i++)
        anim("\xdb");
    gotoxy(15,7);
    anim("NOW LET SEE WHAT DO YOU KNOW ABOUT MY OWNER");
    gotoxy(15,8);
    anim("Please press any key.....");
    getch();
    question();   
}
void loading()
{
    int i;
    for(i=0;i<=20;i++)
    {
        printf("\xdb");
        usleep(10000);
    }
    sleep(1);
}



