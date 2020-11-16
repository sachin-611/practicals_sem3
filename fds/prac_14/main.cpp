#include <iostream>
#include <string>
#include <map>
using namespace std;
template<class t>
class stack
{
    t* arr;
    int index;
    int n;
public:
    stack(int n = 1000)
    {
        this->n = n;
        arr = new t[n];
        index = -1;
    }
    ~stack()
    {
        delete[]arr;
    }
    bool empty()
    {
        return index == -1;
    }
    bool full()
    {
        return index == n - 1;
    }
    void push(t s)
    {
        if (full())
        {
            cout << "Stack full can't push this char " << s << endl;
            return;
        }
        index++;
        arr[index] = s;
    }
    t top()
    {
        return arr[index];
    }
    t pop()
    {
        return arr[index--];
    }
};

bool isbalanced(string s)
{
    int m = s.length();
    stack<char> arr;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            arr.push(s[i]);
        }
        else {
            if (arr.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
            {
                return false;
            }
            if (s[i] == '}')
            {
                if (arr.top() == '{')
                    arr.pop();
                else
                    return false;
            }
            if (s[i] == ')')
            {
                if (arr.top() == '(')
                    arr.pop();
                else
                    return false;
            }
            if (s[i] == ']')
            {
                if (arr.top() == '[')
                    arr.pop();
                else
                    return false;
            }
        }
    }
    return arr.empty();
}

int getWeight(char ch) {
    switch (ch) {
    case '/':
    case '*': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
    }
}

string infixToPostfix(string infix)
{
    if (!isbalanced(infix))
    {
        cout << "Invalid Expression the expression is not well Parenthese!!";
        return "NILL";
    }
    int n = infix.length();
    stack<char> s;
    string postfix = "";
    int i = 0;
    int k = 0;
    while (i < n) {
        char ch = infix[i];
        if (ch == '(') {
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix+= s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
            i++;
            continue;
        }
        int weight = getWeight(ch);
        if (weight == 0) {
            postfix+= ch;

        }
        else {
            if (s.empty()) {
                s.push(ch);
            }
            else {
                while (!s.empty() && s.top() != '(' &&
                    weight <= getWeight(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        i++;
    }
    while (!s.empty()) {
        postfix+= s.top();
        s.pop();
    }
    return postfix;
}

int calculate(int op1, int op2, char operate) {
    switch (operate) {
    case '*': return op2 * op1;
    case '/': return op2 / op1;
    case '+': return op2 + op1;
    case '-': return op2 - op1;
    default: return 0;
    }
}

int evalPostfix(string postfix) {
    stack<int> s;
    int n = postfix.length();
    map<char, int>mp;
    int i = 0;
    char ch;
    int val;
    while (i < n) {
        ch = postfix[i];
        if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
            if (mp.find(ch) != mp.end())
            {
                s.push(mp[ch]);
            }
            else
            {
                cout << "Enter value for " << ch << " : ";
                int a;
                cin >> a;
                mp[ch] = a;
                s.push(mp[ch]);
            }
        }
        else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            val = calculate(op1, op2, ch);
            s.push(val);
        }
        i++;
    }
    return s.top();
}

int main()
{
    string s;
    cout << "Enter infix expression : ";
    cin >> s;
    string ans = infixToPostfix(s);
    if (ans != "NILL")
    {
        cout << "Postfix expression of the given expression is : " << ans << endl;
        cout << "Do you want to evaluate this expression?(Y/N) : ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            int val = evalPostfix(ans);
            cout << "Value of the given expression is : " << val << endl;
        }
    }
    return 0;
}