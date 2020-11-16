#include<iostream>
#include<string>
using namespace std;
class carmanufacturer
{
    string name;
    public:
        carmanufacturer(){
            name="NILL";
        }
        void setName(){
            cout<<"\nEnter Name of car manufacturer:";
            cin>>name;
        }
        void getName(){
            cout<<name;
        }
};
class carmodel:public carmanufacturer
{
    string model_name;
    int model_number;
    public:
        carmodel(){
            model_name="NILL";
            model_number=0;
        }
        void setD(){
            cout<<"Enter Car Model Name:";
            cin>>model_name;
            cout<<"Enter Car Model number:";
            cin>>model_number;
        }
        void getD(){
            cout<<"Car model name is : "<<model_name<<endl;
            cout<<"Car model number is : "<<model_number<<endl;
        } 
};
class car:carmodel
{
    int car_number;
    string car_colour;
    public:
        car()
        {
            car_number = 0;
            car_colour = "NIL";
        }
        void setData(){
            setName();
            setD();
            cout<<"Enter car number : ";
            cin>>car_number;
            cout<<"Enter colour of car : ";
            cin>>car_colour;
        }
        void getData(){
            cout<<"\nCar manufacturer is : ";getName();
            getD();
            cout<<"Car number is : "<<car_number<<endl;
            cout<<"Car colour is : "<<car_colour<<endl;
        }
};
int main(){
    car my_car;
    my_car.setData();
    my_car.getData();
    return 0;
}