#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    int occurenceNumber = 0;
    string fileName;
    string lineRead;
    string toSearch;
    ifstream inputFile;
    cout << "Please enter the name of the file you wish to read.\n";
    cin >> fileName;
    inputFile.open(fileName);
    if(!inputFile){
        cout << "Error opening file, or file doesn't exist!";
        cout << "Try again!\n";
        return 0;
    }
    cout << "Enter the string to search inside file:\n";
    cin >> toSearch;
    cin.ignore();
    while(getline(inputFile, lineRead)){
        if(lineRead.find(toSearch, 0) < lineRead.length()){
            occurenceNumber++;
            cout << lineRead << endl;
            }
    }
    cout << toSearch << " appears " << occurenceNumber;
    cout << " time(s) inside this file.\n";
    inputFile.close();
    return 0;
}
