#include <bits/stdc++.h> 
using namespace std;
int n;
union prize
{
    int cash;
    char momento[50];
};

struct cca_activity
{
    string name, activity_name;
    int year, roll_no, prize_choice;
    union prize prize_to_give;
} cca[100];

void input_data()
{
    cout << "\n Enter the Activity details for : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n " << i + 1 << " student ";
        cout << "\n Roll no. : ";
        cin >> cca[i].roll_no;
        cout << " Name : ";
        cin >> cca[i].name;
        cout << " Year : ";
        cin >> cca[i].year;
        cout << " Activity Name : ";
        cin >> cca[i].activity_name;
        cout << " Activity Prize : 0) Cash  or 1) Momento : ";
        cin >> cca[i].prize_choice;
        cout << " Enter Prize : \t";
        if (cca[i].prize_choice == 1)
            cin >> cca[i].prize_to_give.cash;
        else
            cin >> cca[i].prize_to_give.momento;
    }
}


int main()
{
    cout << "\n Enter the number of participants : ";
    cin >> n;
    input_data();
    cout << "\n	\n";
    cout << setw(10) << "RollNo" << setw(20) << "Name" << setw(20)
         << "Year" << setw(20) << "Activity	Name" << setw(20) << "Prize" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << cca[i].roll_no << setw(20) << cca[i].name << setw(20)
             << cca[i].year << setw(20) << cca[i].activity_name << setw(20);
        if (cca[i].prize_choice == 0)
            cout << cca[i].prize_to_give.cash << endl;
        else
            cout << cca[i].prize_to_give.momento << endl;
    }

    
    return 0;
}