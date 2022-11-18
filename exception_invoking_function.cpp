#include<iostream>
#include<conio.h>
using namespace std;
void divide(int x,int y,int z)
{
    cout<<"\nWe are in divide function\n";
    if((x-y)!=0)
    {
        int r=z/(x-y);
        cout<<"Result:"<<r<<"\n";
    }
    else
    {
        throw(x-y);
    }
    
}
int main()
{
    try
    {
        cout<<"We are inside the try block\n";
        divide(10,20,30);
        divide(10,10,20);
    }
    catch(int i)
    {
        cout<<"Caught the Exception:"<<i;

    }
    getch();
}