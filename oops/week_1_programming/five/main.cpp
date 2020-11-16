#include<iostream>
using namespace std;
class number
{
    int smallest,largest,cur;
    public:
        void getData(){
            while(cur!=-99){
                cout<<"\nEnter number: ";
                cin>>cur;
                if(cur!=-99){
                    smallest=min(smallest,cur);
                    largest=max(largest,cur);
                }
            }
        }
        void showData(){
            cout<<"Largest number is "<<largest<<" and Smallest number is "<<smallest;
        }
};
int main(){
    number n;
    n.getData();
    n.showData();
    return 0;
}
