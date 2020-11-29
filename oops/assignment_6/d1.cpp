#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string>names;
    names.push_back("sachin");
    names.push_back("rahul");
    names.push_back("rimiya");
    names.push_back("aman");
    names.push_back("rohit");
    names.push_back("chinmay");
    names.push_back("monika");
    names.push_back("love");
    for(int i=0;i<names.size();i++)
    {
        cout<<i+1<<"th name is "<<names[i]<<endl;
    }
    sort(names.begin(),names.end());
    cout<<"Names after sorting is:-\n";
    for(int i=0;i<names.size();i++)
    {
        cout<<i+1<<"th name is "<<names[i]<<endl;
    }
    return 0;
}