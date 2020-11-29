#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class hotel_bill
{
public:
    vector<string>items;
    int table_no;
    int total_amount;
    string name;
    hotel_bill(string name,vector<string>&items,int total_amount,int table_no)
    {
        this->name = name;
        this->total_amount = total_amount;
        this->table_no = table_no;
        this->items = items;
    }
    bool operator<(const hotel_bill &i1)
    {
        return (name < i1.name);
    }
};
vector<hotel_bill>all_record;
void print(vector <hotel_bill> &g) 
{ 
    vector <hotel_bill> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
    {
        cout << "name : " << it->name<<endl; 
        cout << "table number : " << it->table_no<<endl; 
        cout << "total amount : " << it->total_amount<<endl; 
        cout << "items : "; 
        for(string i:it->items)
            cout<<i<<" ";
        cout<<endl;
    } 
} 
int main()
{
    int n;
    cout<<"Enter number of record : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        int age,table_no,total_amount,v;
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter table number : ";
        cin>>table_no;
        cout<<"Enter total_amount : ";
        cin>>total_amount;
        cout<<"Enter number of items : ";
        cin>>v;
        vector<string>item(v);
        for(int i=0;i<v;i++)
        {
            cout<<"enter "<<i+1<<"th item : ";
            cin>>item[i];
        }
        hotel_bill r1(name,item,total_amount,table_no);
        all_record.push_back(r1);
    }
    print(all_record);
    sort(all_record.begin(),all_record.end());
    print(all_record);
    return 0;
}