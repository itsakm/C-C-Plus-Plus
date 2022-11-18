#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
class student
{
    private:
        int rollno;
        char name[30];
        class Address
        {
            private:
                int houseno;
                char street[30];
                char city[30];
                char state[30];
                char pincode[10];
            public:
                void setAddress(int h,char const *s,char const *c, char const *s1, char const *p)
                {
                    houseno=h;
                    strcpy(street,s);
                    strcpy(city,c);
                    strcpy(state,s1);
                    strcpy(pincode,p);
                }
                void showAddress()
                {
                    cout<<"Address of student\n";
                    cout<<"\nHouse No:"<<houseno;
                    cout<<"\nStreet No:"<<street;
                    cout<<"\nCity:"<<city;
                    cout<<"\nState:"<<state;
                    cout<<"\nPincode:"<<pincode;
                }
        };
    Address add;
    public:
        void setRollno(int r){rollno=r;}
        void setName(char const *n){strcpy(name,n);}
        void setAddress(int h,char const *s,char const *c,char const *s1,char const *p){add.setAddress(h,s,c,s1,p);}
        void showdata()
        {
            cout<<"Student Details\n";
            cout<<"\nRoll No:"<<rollno;
            cout<<"\nName:"<<name;
            add.showAddress();             
        }
};

int main()
{
    student s1;
    s1.setRollno(10);
    s1.setName("Avanish");
    s1.setAddress(0,"nothing","nothing","nothing","nothing");
    s1.showdata();
    getch();
}