#include <iostream>
#include <fstream>
#include "login.h"
using namespace std;
struct admin
{
    string username;
    string password;
};
bool admin_login(string username,string password) {
    ifstream read_file("secret.txt");
    int file_char_length = 0;
    struct admin *temp = NULL;

    if (!read_file.is_open()) {
        read_file.close();
        return false;
    }
    read_file.seekg(0, read_file.end);
    file_char_length = read_file.tellg();
    if (file_char_length == 0) {
        read_file.close();
        return false;
    }
        temp = new admin;
    read_file.seekg(0, read_file.beg);
    do {
        getline(read_file, temp->username);
        getline(read_file, temp->password);
        if(temp->username==username && temp->password==password)
        {
            read_file.close();
            delete temp;
            cout<<"Welcome "<<username<<", logged in as admin!!"<<endl;
            return true;
        }
    } while (!read_file.eof());
    read_file.close();
    cout<<"Invalid username password!!\nlogged in as user!!"<<endl;
    return false;
}
bool login()
{
    cout<<"\nDo You want to login as admin?(Y/N) : ";
    char ans;
    cin>>ans;
    if(!(ans=='y' || ans=='Y'))
    {
        cout<<"logged in as user!!"<<endl;
        return false;
    }
    string username,password;
    cout<<"Enter username : ";
    cin>>username;
    cout<<"Enter Password : ";
    cin>>password;
    return admin_login(username,password);
}
