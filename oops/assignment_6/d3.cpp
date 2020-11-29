#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class record
{
public:
    string name;
    string id;
    int age;
    string vote;
    record(string name, string id, int age, string vote)
    {
        this->name = name;
        this->id = id;
        this->age = age;
        this->vote = vote;
    }
    bool operator<(const record &i1)
    {
        return (name < i1.name)
    }
};
list<record>election_record;
void print(list <record> g) 
{ 
    list <record> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
    {
        cout << "name : " << it->name<<endl; 
        cout << "id : " << it->id<<endl; 
        cout << "age : " << it->age<<endl; 
        cout << "vote : " << it->vote<<endl; 
    } 
} 
int main()
{
    int n;
    cout<<"Enter number of record : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name,id,vote;
        int age;
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter id : ";
        cin>>id;
        cout<<"Enter age : ";
        cin>>age;
        cout<<"Enter vote : ";
        cin>>vote;
        record r1(name,id,age,vote);
        election_record.push_back(r1);
    }
    print(election_record);
    election_record.sort();
    print(election_record);
    return 0;
}