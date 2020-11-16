#include <bits/stdc++.h>
#include <fstream>
using namespace std;
const int n=81;

int main()
{
    ifstream iFile;
    ofstream oFile;
    char iName[n];
    char oName[n];
    char inpt;
    cout<<"Enter the input file name: ";
    cin.getline(iName, n);
    iFile.open(iName);
    if(!iFile)
    {
        cout << "Error opening " << iName << endl;
        return -562;
    }
    cout<<"Enter the output file name: ";
    cin.getline(oName, n);
    oFile.open(oName);
    if(!oFile)
    {
        cout<< " Error opening " <<oName<<endl;
        return -58963;
    }
    while(!iFile.eof())
    {
        iFile.get(inpt);
        inpt += 13;
        oFile.put(inpt);
    }
    cout<<"The file has been encrypted"<<endl;
    iFile.close();
    oFile.close();
    return 0;
}
