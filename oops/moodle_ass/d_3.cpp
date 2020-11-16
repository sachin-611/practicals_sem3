#include<iostream>
#include<string>
using namespace std;
class checker
{
    int age;
    float income;
    string city;
    char vehicle;
    public:
        checker(){
            age=0;
            income=0;
            city="NILL";
            vehicle='N';
        }
        void getData(){
            cout<<"\n-------------------------------------------\n";
            cout<<"Enter the details of the person :\n ";
            cout<<"\n Enter the age : ";
            cin>>age;
            cout<<" Enter the income : ";
            cin>>income;
            cout<<" Enter the city of residence : ";
            cin>>city;
            cout<<" Does user own a four-wheeler ?(Y/N) ";
            cin>>vehicle;
        }
        
        void check(){
            bool all=true;
            try
            {
                if(age<18 || age>55)
                    throw "Sorry, Age does not meet the required criteria!!";
                cout<<"\n Age meets the criteria";
            }
            catch(char const* exception1)
            {
                all=false;
                cout<<"\n"<<exception1;
            }

            try
            { 
                if(income<50000 || income>100000)
                    throw "Sorry, Income does not meet the required criteria!!";
                cout<<"\n Income meets the criteria";
            }
            catch(char const* exception2)
            {
                all=false;
                cout<<"\n"<<exception2;
            }

            try
            {
                if(city!="Pune" && city!="Mumbai" && city!="Bangalore" && city!="Chennai")
                    throw " Sorry, City of residence does not meet the criteria !!";
                cout<<"\n City of residence meets the criteria ";
            }
            catch(char const* exception3)
            {
                all=false;
                cout<<"\n"<<exception3;
            }

            try
            { 
                if(vehicle == 'N' || vehicle == 'n')
                    throw "Sorry, Vehicle criteria is not fulfilled !!";
                cout<<"\n Vehicle criteria is fulfilled ";
            }
            catch(char const *exception4)
            {
                all=false;
                cout<<"\n"<<exception4;
            }
            
            if(all)
                cout<<"\nCongrats!! You met all criteria!!"<<endl;
            else
                cout<<"\nOOOPPPPPSSSS!! You did not meet all criteria!!";
        }
};
int main()
{
    checker data_1;
    data_1.getData();
    data_1.check();
    return 0;
}