#include <bits/stdc++.h>
using namespace std;

class maping
{
public:
    map<string, int> m;
    void get_data()
    {
        string s;
        cout << "Enter the state name : " << endl;
        cin >> s;
        cout << "Enter the population of state : " << endl;
        cin >> m[s];
    }
    void give_data()
    {
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
            cout << "state " << it->first << " contains " << it->second << "people " << endl;
    }
    void find_state(string s)
    {
        cout << "state " << s << " contains " << m[s] << " peoples " << endl;
    }
    void erase(string s)
    {
        m.erase(s);
        give_data();
    }
};

void display_menu()
{
    cout << "\n1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice : " << endl;
}

int main()
{
    maping obj;

    while (1)
    {
        display_menu();
        int choice;
        cin >> choice;
        while (!(choice >= 1 && choice <= 5))
        {
            display_menu();
            cin >> choice;
        }
        if (choice == 1)
        {
            obj.get_data();
            cout << "Sucessfully inserted!!" << endl;
        }
        else if (choice == 2)
        {
            string state;
            cout << "Enter state to be searched :";
            cin >> state;
            if (obj.m.find(state) != obj.m.end())
            {
                obj.find_state(state);
                cout<<"\n";
            }
            else
            {
                cout << "The record of this state does not exist!!" << endl;
            }
        }
        else if (choice == 3)
        {
            string state;
            cout << "Enter state name to delete data : ";
            cin >> state;
            if (obj.m.find(state) != obj.m.end())
            {
                obj.erase(state);
                cout << "Sucessfully deleted the data of " << state << " State!!" << endl;
            }
            else
            {
                cout << "This city does not exist in the database cannot delete!!" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "\nData of all the states : \n\n";
            obj.give_data();
            cout<<"\n";
        }
        else
        {
            cout << "Exiting!!!" << endl;
            break;
        }
    }
    return 0;
}