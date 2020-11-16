#include<iostream>
using namespace std;
class magic_date
{
    int month,day,year;
    string result;
    public:
        void getData(){
            cout<<"\nEnter Day(Number):";
            cin>>day;
            cout<<"\nEnter Month(Number):";
            cin>>month;
            cout<<"\nEnter Year(Number of type YY): ";
            cin>>year;
        }
        void showData(){
            cout<<"\nDate "<<day<<"/"<<month<<"/"<<year<<result;
        }
        void calculate(){
            if(year==day*month){
                result=" is Magic Date";
            }else{
                result=" is not Magic Date";
            }
        }
};
int main(){
    char ans;
    magic_date d;
    do
    {
        d.getData();
        d.calculate();
        d.showData();
        cout<<"\nDo you want to continue?(Y/N)";
        cin>>ans;
    } while (ans=='Y' || ans=='y');

    return 0;
}
