#include <bits/stdc++.h>
using namespace std;

struct store
{
    int ItemNumber;
    string ItemNames;
    int ItemCateogory;
    double price;
    string manufacturing_date;
    int stockQuantity;
};
store s[25];
int n;
void display_data(){
    cout<<"\t\t*********************************\n"<<endl;
    cout<<"ITEMS IN THE SHOP"<<endl;
    for(int j=0;j<n;j++){
    cout<<"ITEM NUMBER:- "<<s[j].ItemNumber<<endl;
    cout<<"ITEM NAME:- "<<s[j].ItemNames<<endl;
    cout<<"ITEM MANUFACTURING DATE:- "<<s[j].manufacturing_date<<endl;
    cout<<"ITEM PRICE:- "<<s[j].price<<endl;
    if(s[j].ItemCateogory==1){
        cout<<"ITEM CATEOGORY IS:- ELECTRONICS"<<endl;
    }
    if(s[j].ItemCateogory==2){
        cout<<"ITEM CATEOGORY IS:- FOOD"<<endl;
    }
    if(s[j].ItemCateogory==3){
        cout<<"ITEM CATEOGORY IS:- COSMETICS"<<endl;
    }
    if(s[j].stockQuantity==0){
        cout<<"ITEM NOT AVAILABLE."<<endl;
    }
    if(s[j].stockQuantity!=0){
        cout<<"ITEM QUANTITY IS:- "<<s[j].stockQuantity<<endl;
    }
    cout<<"\t\t****************************"<<endl;
    }
}
void input_data()
{
    cout<<"\t\t********************************************"<<endl;
    cout<<endl;
    cout<<"Please Enter the number of entries:- ";
    cin>>n;
    cout<<"\t\tPlease Provide the information for the shop."<<endl;
    for(int i=0;i<n;i++){
    cout<<"\t\t********************************************"<<endl;
    cout<<"Entry Number:- "<<i+1<<endl;
    cout<<"Enter the Item number:- ";
    cin>>s[i].ItemNumber;
    cout<<"Enter the Name of the Item:- ";
    cin>>s[i].ItemNames;
    cout<<"Please Enter the type of item(1.Electronics  2.Food   3,Cosmetics):- ";
    cin>>s[i].ItemCateogory;
    cout<<"Enter the price of the item:- ";
    cin>>s[i].price;
    cout<<"Enter the manufacturing date in the format dd/mm/yy:- ";
    cin>>s[i].manufacturing_date;
    cout<<"Enter the quantity of the item:- ";
    cin>>s[i].stockQuantity;
    }
}

int main()
{
    input_data();
    display_data();
    return 0;
}