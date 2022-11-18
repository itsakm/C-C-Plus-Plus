#include<iostream>
#include<conio.h>
using namespace std;
void test(int x) throw(int,char,double)
{
    if(x==0) throw 'x';
    else
        if (x==1) throw x;
    else 
        if(x==-1) throw 1.0;
    cout<<"End of function block\n";
    
}
int main()
{
    try
    {
        cout<<"Testing the Throw Restriction\n";
       cout<<"x==0\n";
        test(0);
        cout<<"x==1\n";
        test(1);
        cout<<"x==-1\n";
        test(-1);
        cout<<"x==2\n";
        test(2);

    }
    catch(char c)
    {
        cout<<"Caught a Character\n"<<c;

    }
    catch(int m)
    {
        cout<<"Caught a integer\n"<<m;
        
    }
    catch(double d)
    {
        cout<<"Caught a double\n";
        
    }
    cout<<"End of try catch system\n";
    getch();
}