#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string fileName;
    string lineRead;
    ifstream inputFile;
    cout << "Please enter the name of the file you wish to read.\n";
    cin >> fileName;
    inputFile.open(fileName);
    if(!inputFile)
        cout << "Error opening file, or file doesn't exist!";
    cin.ignore();
    for(int counter = 0; counter < 10; counter++){
        if(inputFile.eof()){
            cout << "End of file reached!\n";
            break;
        }
        getline(inputFile, lineRead);
        cout << lineRead << endl;
    }
    inputFile.close();
    return 0;
}
