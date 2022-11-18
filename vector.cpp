#include<iostream>
#include<vector>
using namespace std;
void display(vector <int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"  ";

    }
    cout<<"\n";
}
int main()
{
    vector<int> v;
    cout<<"Initial Size:"<<v.size()<<"\n";
    //putting values into the vector
    int x;
    cout<<"Enter the five integer item";
    for(int i=0;i<5;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"Size after the entering the values:"<<v.size()<<"\n";
    //Display the contents
    display(v);
    //Add one more values
    v.push_back(6.6);//here float value will be truncated to  int 
    //Display size 
    cout<<"\nSize="<<v.size()<<"\n";
    display(v);
    //inserting elements using iterator
    vector<int>:: iterator itr = v.begin();
    itr=itr+3;
    v.insert(itr,1,9);
    cout<<"\nContents after inserting:\n";
    display(v);

    //Removing the elements
    v.erase(v.begin()+3,v.begin()+5);
    //display the contents
    cout<<"\nContents after deletion:\n";
    display(v);
    cout<<"End\n";
    return(0);
}