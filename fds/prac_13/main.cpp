#include <iostream>
#include <string>
using namespace std;

class stack
{
    char *arr;
    int index;
    int n;
    public:
        stack(int n=1000)
        {
            this->n=n;
            arr=new char[n];
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
        void push(char s)
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

bool isbalanced(string s)
{
    int m=s.length();
    stack arr;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            arr.push(s[i]);
        }
        else{
            if(arr.empty() && (s[i]==')' || s[i]==']' || s[i]=='}'))
            {
                return false;
            }
            if(s[i]=='}')
            {
                if(arr.top()=='{')
                    arr.pop();
                else
                    return false;
            }
            if(s[i]==')')
            {
                if(arr.top()=='(')
                    arr.pop();
                else
                    return false;
            }
            if(s[i]==']')
            {
                if(arr.top()=='[')
                    arr.pop();
                else
                    return false;
            }
        }
    }
    return arr.empty();
}
int main()
{
    string s;
    cout<<"Enter string to be checked : ";
    cin>>s;
    if(isbalanced(s))
    {
        cout<<s<<" is balanced parantheses!!"<<endl;
    }
    else
    {
        cout<<s<<" is not balanced parantheses!!"<<endl;
    }
    return 0;
}