#include<iostream>
using namespace std;
class roman_converter
{
    int number;
    string result;
    public:
    void getData(){
        cout<<"\nEnter number to be converted into Roman number:";
        cin>>number;
        while(number<1 || number>10 ){
            cout<<"\nPlease enter another number between 1 and 10:";
            cin>>number;
        }
    }

    void showData(){
        cout<<"\nNumber "<<number<<" in Roman number system is "<<result;
    }
    void convert(){
        switch(number)
        {
            case 1: result="i";
                    break;

            case 2: result="ii";
                    break;
            case 3: result="iii";
                    break;
            case 4: result="iv";
                    break;
            case 5: result="v";
                    break;
            case 6: result="vi";
                    break;
            case 7: result="vii";
                    break;
            case 8: result="viii";
                    break;
            case 9: result="ix";
                    break;
            case 10: result="x";
                    break;
        }
    }
};
int main(){
    char ans;
    roman_converter r;
    do
    {
        r.getData();
        r.convert();
        r.showData();
        cout<<"\nDo you want to continue?(Y/N)";
        cin>>ans;
    } while (ans=='Y' || ans=='y');

    return 0;
}
