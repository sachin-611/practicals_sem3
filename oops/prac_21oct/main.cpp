#include<iostream>
#include <string>
#include<fstream>
using namespace std;
static int cid=1000;
class bank
{
    int id;
    string name;
    double balance;
    public:
        bank()
        {
            id=cid;
            cid++;
            cout<<"Enter name : ";
            cin>>name;
            cout<<"Enter starting balance : ";
            cin>>balance;
        }
};
int main()
{
    ofstream w("customer.bat",ios::in | ios::binary);
    if(!w)
    {
        cout<<"Cannot open file"<<endl;
        return 253;
    }
    for(int i=0;i<5;i++)
    {
        bank obj;
        w.write((char *)&obj,sizeof(obj));
    }
    w.close();
    if(!w.good())
    {
        cout<<"error occured";
        return 563;
    }
    cout<<"\nWritten file sucessfully!!"<<endl;
    return 0;
}