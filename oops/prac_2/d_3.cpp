#include <bits/stdc++.h>

using namespace std;
struct drink_machine
{
    string drink_name;
    int drink_cost;
    int number_of_drinks;
};
drink_machine m[5];

int main()
{
    char d='Y';
    cout<<"\t\t*********************************"<<endl;
    cout<<"\t\tDRINK MACHINE STIMULATOR"<<endl;
    m[0].drink_name="Cola";
    m[0].drink_cost=25;
    m[0].number_of_drinks=20;
    m[1].drink_name="Froot Bear";
    m[1].drink_cost=25;
    m[1].number_of_drinks=20;
    m[2].drink_name="Lemon Lime";
    m[2].drink_cost=25;
    m[2].number_of_drinks=20;
    m[3].drink_name="Grape Soda";
    m[3].drink_cost=50;
    m[3].number_of_drinks=20;
    m[4].drink_name="Cream Soda";
    m[4].drink_cost=50;
    m[4].number_of_drinks=20;
    cout<<"Drinks Available:- "<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<"."<<m[i].drink_name<<" Rs-"<<m[i].drink_cost<<endl;
    }
    int choice;
    int amount;
    int change;
    double moneyEarned=0;
    while(d!='N'){
        cout<<"Which drink you want to buy:- ";
        cin>>choice;
        cout<<"You choose "<<m[choice-1].drink_name<<endl;
        if(m[choice-1].number_of_drinks==0){
            cout<<"Drink not available.Choose another drink."<<endl;
            continue;
        }
        cout<<"Enter the amount of money you insert in machine:- ";
        cin>>amount;
        if(amount<0 || amount>150){
            cout<<"Amount not acceptable.Please Enter valid amount between (1,150)"<<endl;
            continue;
        }
        change=amount-(m[choice-1].drink_cost);
        cout<<"Change you get from your paid amount is:- "<<change<<endl;
        m[choice-1].number_of_drinks-=1;
        moneyEarned+=(m[choice-1].drink_cost);
        cout<<"\nDo you want to continue(Y/N):- ";
        cin>>d;
        if(d=='N' || d=='n'){
            cout<<"\n\n\t\tThank You"<<endl;
            break;
        }
    }
    cout<<"Total Money earned by the machine is:- "<<moneyEarned<<endl;

    return 0;
}