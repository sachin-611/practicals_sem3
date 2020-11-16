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
            name="";
            id=0;
            balance=0;
        }
        void withdraw();
        void deposit();
        void display();
        int getid();
};

int bank::getid()
{
    return id;
}
void bank::display()
{
    cout<<"\nName : "<<name<<endl;
    cout<<"Customer id : "<<id<<endl;
    cout<<"Balance : "<<balance<<endl;
}
 
void bank::withdraw()
{
    int n;
    cout<<"\nEnter amount to be withdraw : ";
    cin>>n;
    while(n>balance)
    {
        cout<<endl<<"\nWithdrawing amount cannot be more ther current balance"<<endl<<"Enter appropriate amount : ";
        cin>>n;
    }
    balance-=n;
    cout<<"\nSucessfully withdrawn "<<n<<" form current balance\n";
}

void bank::deposit()
{
    int n;
    cout<<"\nEnter amount to be deposit : ";
    cin>>n;
    balance+=n;
    cout<<"\nSucessfully deposited "<<n<<" into your account\n";
}

void display()
{
    ifstream r("customer.bat",ios::out | ios::binary);
    if(!r)
    {
        cout<<"Error in opening"<<endl;
        exit(45);
    }
    for(int i=0;i<5;i++)
    {
        bank a;
        r.read((char *)&a,sizeof(bank));
        a.display();
    }
    r.close();
    if(!r.good())
    {
        cout<<"Error at reading";
        exit(4587);
    }
}
void transaction(bank arr[])
{
    int n;
    cout<<"Enter number of transaction : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int id;
        cout<<"Enter customer id:";
        cin>>id;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(id==arr[i].getid())
            {
                ind=i;
                break;
            }
        }
        while(id==-1)
        {
            cout<<"\nInvalid id !!\nPlease enter valid customer id:";
            cin>>id;
            int ind=-1;
            for(int i=0;i<n;i++)
            {
                if(id==arr[i].getid())
                {
                    ind=i;
                    break;
                }
            }
        }
        cout<<"1. For deposit\n 2. For withdraw\n";
        int choice;
        cin>>choice;
        while(choice!=1 && choice!=2)
        {
            cout<<"Invalid choice\n1. For deposit\n 2. For withdraw\nEnter valid choice :";
            cin>>choice;
        }
        if(choice==1)
            arr[i].deposit();
        if(choice==2)
            arr[i].withdraw();
    }
    cout<<"\ntransaction completed\n";
}
void update(bank arr[])
{
    ofstream w("customer.bat",ios::in | ios::binary);
    if(!w)
    {
        cout<<"Cannot open file"<<endl;
        exit(253);
    }
    for(int i=0;i<5;i++)
    {
        w.write((char *)&arr[i],sizeof(arr[i]));
    }
    w.close();
    if(!w.good())
    {
        cout<<"error occured";
        exit(563);
    }
    cout<<"\nWritten file sucessfully!!"<<endl;
}
int main()
{
    ifstream r("customer.bat",ios::out | ios::binary);
    if(!r)
    {
        cout<<"Error in opening"<<endl;
        return 4587;
    }
    bank arr[5];
    for(int i=0;i<5;i++)
    {
        r.read((char *)&arr[i],sizeof(bank));
    }
    r.close();
    if(!r.good())
    {
        cout<<"Error at reading";
        return 58745;
    }
    display();
    transaction(arr);
    update(arr);
    display();
    return 0;
}
