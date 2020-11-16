#include<iostream>
using namespace std;
class colour_mixer
{
    string colour1,colour2,result;
    public:
        void getData(){
            cout<<"\nEnter Primary Colour : ";
            cin>>colour1;
            while(!(colour1=="red" || colour1=="blue" || colour1=="yellow")){
                cout<<"\nPlease enter \"red\" ,\"blue\" or \"yellow\"!! \nEnter colour : ";
                cin>>colour1;
                continue;
            }
            cout<<"\nEnter another Primary colour to be mixed : ";
            cin>>colour2;
            while(!(colour2=="red" || colour2=="blue" || colour2=="yellow")){
                cout<<"\nPlease enter \"red\" ,\"blue\" or \"yellow\"!! \nEnter colour : ";
                cin>>colour2;
                continue;
            }
        }
        void showData(){
            cout<<"\nOn mixing "<<colour1<<" and "<<colour2<<" results in "<<result;
        }
        void mix_colour(){
            if((colour1=="red" && colour2=="blue") || (colour1=="blue" && colour2=="red")){
                result="purple";
            }
            else if((colour1=="red" && colour2=="yellow") || (colour1=="yellow" && colour2=="red")){
                result="orange";
            }
            else if((colour1=="yellow" && colour2=="blue") || (colour1=="blue" && colour2=="yellow")){
                result="green";
            }
        }
};
int main(){
    char ans;
    colour_mixer cm;
    do
    {
        cm.getData();
        cm.mix_colour();
        cm.showData();
        cout<<"\nDo you want to continue?(Y/N)";
        cin>>ans;
    } while (ans=='Y' || ans=='y');

    return 0;
}
