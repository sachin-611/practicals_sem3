#include <iostream>
#include <string>
#include "address_book.h"
#include "login.h"
using namespace std;
int main()
{
    cout << "********************\n";
    cout << "Welcome User!\n";
    cout << "This is AIT'S Address Book Application!\n";
    cout << "--------------------\n";
    if(login())
        run_program();
    else
        program();
    cout << "--------------------\n";
    cout << "Application terminated\n";
    cout << "********************\n";
    return 0;
}
