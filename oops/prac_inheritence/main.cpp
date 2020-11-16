#include<bits/stdc++.h>
using namespace std;
class personal
{
protected:
    int roll_no,age;
    string name,gender;

};
class professional
{
protected:
    string known_pl,known_env,area_of_interest;
};
class academic
{
protected:
    double ssc,hsc,fe;
    string extra_activity;
};
class bio_data: public personal,public professional,public academic
{
public:
    void inputData()
    {
        cout<<"Please provide the information :- "<<endl;
        cout<<"Enter the name :- ";
        fflush(stdin);
        getline(cin,name);
        fflush(stdin);
        cout<<"Enter the roll number :- ";
        cin>>roll_no;
        cout<<"Enter the gender of person :- ";
        cin>>gender;
        cout<<"Enter the age of the person :- ";
        cin>>age;
        cout<<"Known programming languages :- ";
        fflush(stdin);
        getline(cin,known_pl);
        cout<<"Known IDEs : ";
        fflush(stdin);
        getline(cin,known_env);
        fflush(stdin);
        cout<<"Enter the Area of interest :- ";
        getline(cin,area_of_interest);
        fflush(stdin);
        cout<<"Enter ssc percentage :- ";
        cin>>ssc;
        cout<<"Enter hsc percentage :- ";
        cin>>hsc;
        cout<<"Enter FE percentage :- ";
        cin>>fe;
        fflush(stdin);
        cout<<"Extra-curricular Activities :- ";
        getline(cin,extra_activity);

    }
    void showData()
    {
        cout<<"\n\n\n\n**********************************************\n\n";
        cout<<"\nCurricular Vitae for : "<<name<<endl;
        cout<<"Roll number :- "<<roll_no<<endl;
        cout<<"Gender :- "<<gender<<endl;
        cout<<"Age of person :- "<<age<<endl;
        cout<<"Known programming languages :- "<<known_pl<<endl;
        cout<<"Known IDEs :- "<<known_env<<endl;
        cout<<"Area of interest is :- "<<area_of_interest<<endl;
        cout<<"SSC percentage is :- "<<ssc<<endl;
        cout<<"HSC percentage is :- "<<hsc<<endl;
        cout<<"FE percentage is :- "<<fe<<endl;
        cout<<"Extra-curricular Activities :- "<<extra_activity<<endl;
        cout<<"\t\t*************************"<<endl;
    }
};


int main()
{
    bio_data p1;
    p1.inputData();
    p1.showData();
    return 0;
}
