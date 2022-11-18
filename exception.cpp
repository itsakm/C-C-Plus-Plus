#include<conio.h>
#include<iostream>
using namespace std;

int main()
{
    cout<<"Welcome";
    try
    {
        throw 10;
        cout<<"\n In try";
    }
    catch(int n)
    {
        cout<<"\n Exception No:"<<n;
    }
    cout<<"\nlast line";
    getch();
    
}