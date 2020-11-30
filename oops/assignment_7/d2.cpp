#include <iostream>
#include <set>
#include <string>
using namespace std;

template<class t>
class sets
{
    set<t>s1;
public:
    void insert_value()
    {
        t temp;
        cout<<"Enter value : ";
        cin>>temp;
        s1.insert(temp);
        cout<<"value sucessfully added\n";
    }
    void delete_value()
    {
        t temp;
        cout<<"Enter value to be deleted : ";
        cin>>temp;
        s1.erase(temp);
    }
    void get_size()
    {
        cout<<"Size is : "<<s1.size()<<endl;
    }
    bool search(t value)
    {
        return s1.find(value)!=s1.end();
    }
    void display()
    {
        cout<<"Displaying set : "<<endl;
        for(t i:s1)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

void display_menu()
{
    cout<<"\n\nMenu"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Size"<<endl;
    cout<<"4. Search"<<endl;
    cout<<"5. Display"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice : ";
}

int main()
{
    sets<int> obj;
    sets<string>obj1;
    cout<<"Set operations on int set!!";
    while(1)
    {
        display_menu();
        int choice;
        cin>>choice;
        while(!(choice>=1 && choice<=6))
        {
            display_menu();
            cin>>choice;
        }
        if(choice==1)
        {
            obj.insert_value();
        }
        else if(choice==2)
        {
            obj.delete_value();
        }
        else if(choice ==3)
        {
            obj.get_size();
        }
        else if(choice ==4)
        {
            int num;
            cout<<"Enter number to be searched : ";
            cin>>num;
            if(obj.search(num))
            {
                cout<<num<<" is present !!";
            }
            else
            {
                cout<<num<<" is not present !!";
            }
            
        }
        else if(choice ==5)
        {
            obj.display();
        }
        else
        {
            cout<<"Exiting!!";
            break;
        }
    }
    cout<<"Set operations on string set!!";
    while(1)
    {
        display_menu();
        int choice;
        cin>>choice;
        while(!(choice>=1 && choice<=6))
        {
            display_menu();
            cin>>choice;
        }
        if(choice==1)
        {
            obj1.insert_value();
        }
        else if(choice==2)
        {
            obj1.delete_value();
        }
        else if(choice ==3)
        {
            obj1.get_size();
        }
        else if(choice ==4)
        {
            string num;
            cout<<"Enter string to be searched : ";
            cin>>num;
            if(obj.search(num))
            {
                cout<<num<<" is present !!";
            }
            else
            {
                cout<<num<<" is not present !!";
            }
        }
        else if(choice ==5)
        {
            obj1.display();
        }
        else
        {
            cout<<"Exiting!!";
            break;
        }
    }
    return 0;
}