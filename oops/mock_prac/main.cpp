/******************************************************************************

Develop an object-oriented program in C++ to create a database of student information system
containing the following information: Name, Roll number, Class, division, Date of Birth, Blood group,
Contact address, telephone number, driving license no. and other. Construct the database with suitable
member functions for initializing and destroying the data viz constructor, default constructor, Copy
constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class student;
class studentData
{
    string address;
    long int *telephone;
    long int*drivingLicenseNumber;
public:
    friend class student;
    studentData(string address="",long int number=0,long int driving=0)
    {
        this->address=address;
        telephone=new long int;
        *telephone=number;
        drivingLicenseNumber=new long int;
        *drivingLicenseNumber=driving;
    }
    ~studentData()
    {
        delete telephone;
        delete drivingLicenseNumber;
    }
    void getStudentData()
    {
        cout<<"Enter Contact Address : ";
        cin.get();
        getline(cin,address);
        cout<<"Enter telephone number : ";
        cin>>*telephone;
        cout<<"Enter Driving license number : ";
        cin>>*drivingLicenseNumber;
    }
    void displayStudentData()
    {
        cout<<"Contact Address : "<<address<<endl;
        cout<<"Telephone number : "<<*telephone<<endl;
        cout<<"Driving license Number : "<<*drivingLicenseNumber<<endl;
    }
};

class student
{
    string name,dateOfBirth,bloodGroup,class_;
    int *rollNo;
    char *division;
    static int count;
public:
    student(string name="",int rollno=0,int div_='-',string bloodGroup="",string dateOfBirth="--/--/----",string class_="")
    {
        this->name=name;
        rollNo=new int;
        *rollNo=rollno;
        this->class_=class_;
        division=new char;
        *division=div_;
        this->dateOfBirth=dateOfBirth;
        this->bloodGroup=bloodGroup;
    }
    student(student &s2)
    {
        name=s2.getName();
        dateOfBirth=s2.getdob();
        bloodGroup=s2.getbloodgrp();
        class_=s2.getclass_();
        rollNo=new int;
        *rollNo=s2.getrollno();
        division=new char;
        *division=s2.getdivision();
    }
    string getName()
    {
        return name;
    }
    string getdob()
    {
        return dateOfBirth;
    }
    string getbloodgrp()
    {
        return bloodGroup;
    }
    string getclass_()
    {
        return class_;
    }
    int getrollno()
    {
        return *rollNo;
    }
    char getdivision()
    {
        return *division;
    }
    static int getCount()
    {
        return count;
    }
    void getData(studentData*);
    void displayData(studentData*);
    ~student()
    {
        delete rollNo;
        delete division;
    }
};
int student::count;

inline void student::getData(studentData *s1)
{
    cout<<"Enter Student Name : ";
    cin.get();
    getline(cin,name);
    cout<<"Enter Roll Number : ";
    cin>>*rollNo;
    cout<<"Enter class : ";
    cin.get();
    getline(cin,class_);
    cout<<"Enter Division : ";
    cin>>*division;
    cout<<"Enter Date of Birth : ";
    cin.get();
    getline(cin,dateOfBirth);
    cout<<"Enter blood group : ";
    cin>>bloodGroup;
    s1->getStudentData();
    count++;
}

inline void student::displayData(studentData *s1)
{
    cout<<"Name : "<<name<<endl;
    cout<<"Roll number : "<<*rollNo<<endl;
    cout<<"Class : "<<class_<<endl;
    cout<<"Division : "<<*division<<endl;
    cout<<"Date of birth : "<<dateOfBirth<<endl;
    cout<<"bloodGroup : "<<bloodGroup<<endl;
    s1->displayStudentData();
}

int main()
{
    int n;
    cout<<"Enter number of student : ";
    cin>>n;
    student *st1[n];
    studentData *st2[n];
    for(int i=0;i<n;i++)
    {
        student *temp1=new student;
        studentData *temp2=new studentData;
        temp1->getData(temp2);
        st1[i]=temp1;
        st2[i]=temp2;
    }
    cout<<"Total number of student are : "<<student::getCount()<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------"<<endl;
        cout<<"Data of student "<<i+1<<endl;
        cout<<"---------------------------------------------"<<endl;
        st1[i]->displayData(st2[i]);
    }
    for(int i=0;i<n;i++)
    {
        delete st1[i];
        delete st2[i];
    }
    return 0;
}

