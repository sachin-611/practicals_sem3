#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    string fileName;
    string lineRead;
    char ch;
    ifstream inputFile;
    cout << "Please enter the name of the file you wish to read"<<endl;
    cin >> fileName;
    inputFile.open(fileName);
    if(!inputFile){
        cout << "Error opening file, or file doesn't exist!"<<endl;
        cout << "Try again!"<<endl;
        return 0;
    }
    cin>>choice;
    if(choice==1){
        while(!inputFile.eof()){
        inputFile.get(ch);
        if(ch>=97 && ch<=122)
          {
               ch=toupper(ch);
          }
          cout << ch ;
    }
    cout<<endl;
    cout<<endl<<"Characters have been changed to uppercase"<<endl;
    }
    if(choice==2){
        while(!inputFile.eof()){
        inputFile.get(ch);
        int val= int(ch);
        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
        cout << bin << " ";
    }
    cout<<endl;
    cout<<endl<<"Characters have been changed to binary form"<<endl;
    }
    inputFile.close();
    return 0;
}
