#include<bits/stdc++.h>
using namespace std;
class rand_number
{
    int ans;
    int count=0;
    public:
        void generate(){
            srand (time(NULL));
            ans = rand() % 100 + 1;
        }
        void guess(){
            int gs;
            cout<<"\nGuess the number from 1 to 100 : ";
            count++;
            cin>>gs;
            while(gs!=ans){
                if(gs>ans){
                    cout<<"\nGuessed number is too high!! try again : ";
                }else{
                    cout<<"\nGuessed number is too small!! try again : ";
                }
                count++;
                cin>>gs;
            }
            cout<<"\nCorrect guess!!";
        }
        void result(){
            cout<<"\nYou were able to guess the number correct on "<<count<<"th try!!";
        }
};
int main(){
    rand_number n;
    n.generate();
    n.guess();
    n.result();
    return 0;
}
