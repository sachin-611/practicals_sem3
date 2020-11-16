#include <iostream>
#include <string>
using namespace std;
template <class t>
class stack
{
    t *arr;
    int index;
    int n;
    public:
        stack(int n=1000)
        {
            this->n=n;
            arr=new t[n];
            index=-1;
        }
        ~stack()
        {
            delete []arr;
        }
        bool empty()
        {
            return index==-1;
        }
        bool full()
        {
            return index==n-1;
        }
        void push(t s)
        {
            if(full())
            {
                cout<<"Stack full can't push this char "<<s<<endl;
                return;
            }
            index++;
            arr[index]=s;
        }
        char top()
        {
            return arr[index];
        }
        char pop()
        {
            return arr[index--];
        }
};
string reverse_string(string s)
{
    int m=s.length();
    stack <char>arr;
    for(int i=0;i<m;i++)
    {
        arr.push(s[i]);
    }
    string ans="";
    for(int i=0;i<m;i++)
    {
        ans+=arr.top();
        arr.pop();
    }
    return ans;
}

int convert_to_binary(string s)
{
    int m=s.length();
    stack<int>arr;
    for(int i=m-1;i>=0;i--)
    {
        (s[i]=='0')?arr.push(0):arr.push(1);
    }
    int val=1;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans+=(arr.top()==1)?val:0;
        val*=2;
        arr.pop();
    }
    return ans;
}

int main()
{
    string s;
    cout<<"Enter string to be reversed : ";
    cin>>s;
    cout<<"Reversed string is : "<<reverse_string(s)<<endl;

    string binary;
    cout<<"\nEnter binary : ";
    cin>>binary;
    cout<<"Decimal form of the given binary is : "<<convert_to_binary(binary);
    return 0;
}
