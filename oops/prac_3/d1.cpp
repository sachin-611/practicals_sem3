#include <bits/stdc++.h>
using namespace std;
class student
{
    char *name, *branch;
    int roll_no;

public:
    student()
    {
    }
    student(char n[], int r, char br[])
    {
        strcpy(name, n);
        roll_no = r;
        strcpy(branch, br);
    }
    void *operator new(size_t size)
    {
        void *p;
        p = malloc(size);
        (reinterpret_cast<student *>(p))->name = reinterpret_cast<char *>(malloc(16));
        (reinterpret_cast<student *>(p))->branch = reinterpret_cast<char *>(malloc(5));
        return p;
    }
    void operator delete(void *p)
    {
        free(reinterpret_cast<void *>(reinterpret_cast<student *>(p)->name));
        free(reinterpret_cast<void *>(reinterpret_cast<student *>(p)->branch));
        free(p);
    }
    void putdata()
    {
        cout << "\nName : " << name << "\nRoll No : " << roll_no << "\nBranch : " << branch;
    }
};

int main()
{
    int n;
    int roll_no;
    char branch[10], name[10];
    student *s[10];
    cout << "\nenter the no. of students:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Name : ";
        cin >> name;
        cout << "\nEnter roll no : ";
        cin >> roll_no;
        cout << "\nEnter branch : ";
        cin >> branch;
        s[i] = new student(name, roll_no, branch);
    }
    cout << "\nStudent Details\n";
    for (int i = 0; i < n; i++)
    {
        s[i]->putdata();
        delete s[i];
    }
    return (0);
}