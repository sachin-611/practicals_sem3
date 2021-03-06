#include <iostream>
#include <string>
#include "record.h"
#include "llist.h"
#include "address_book.h"
using namespace std;

int get_menu_selection2() {
    int selection = 0;
    cin >> selection;
<<<<<<< HEAD
    while (cin.fail() || selection < 1 || selection > 5) {
        if (cin.fail()) {
            cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 5) {
=======
    while (cin.fail() || selection < 1 || selection > 4) {
        if (cin.fail()) {
            cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 4) {
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
            cout << "Not a valid choice.\n";
            display_commands();
        }
        cin.clear();
        cin.ignore(256, '\n');
        cin >> selection;
    }
    cin.clear();
    return selection;
}

void display_command_user() {
    cout << "Usage:\n";
    cout << "\t1: Print information about a record using the name as the key. \n";
    cout << "\t2: Print information about a record using the phone number as the key. \n";
<<<<<<< HEAD
    cout << "\t3: Print information about a record using the address as the key. \n";
    cout << "\t4: Print all information in the database.\n";
    cout << "\t5: Quit the program.\n";
=======
    cout << "\t3: Print all information in the database.\n";
    cout << "\t4: Quit the program.\n";
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
    cout << "What would you like to do?\n";
    return;
}
void program()
{
    llist records(get_file_name());
    int menu_selection = 0;
    string input_name;
    string input_phone;
    string input_address;
    display_command_user();
    do {
        menu_selection = get_menu_selection2();
        switch (menu_selection) {
            case 1:
                cout << "--------------------\n";
                cout << "Print Record(s) with the same name\n";
                input_name = get_name();
                records.print_record(input_name,0);
                break;
            case 2:
                cout << "--------------------\n";
                cout << "Print Record(s) with the same phone number\n";
                input_phone=get_phone_number();
                records.print_record_phone(input_phone);
                break;
<<<<<<< HEAD
             case 3:
                cout << "--------------------\n";
                cout << "Print Record(s) with the same address\n";
                input_address=get_address();
                records.print_record_address(input_address);
                break;
            case 4:
=======
            case 3:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Printing Records...\n";
                records.print_all_records();
                break;
        }
<<<<<<< HEAD
        if (menu_selection != 5) {
            display_command_user();
        }
    } while (menu_selection != 5);
=======
        if (menu_selection != 4) {
            display_command_user();
        }
    } while (menu_selection != 4);
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
    return;
}

void run_program() {
    llist records(get_file_name());
    string input_name = "";
    string input_address = "";
    string input_phone = "";
    string dummy = "";
    int input_year = 0;
    int menu_selection = 0;

    display_commands();
    do {
        menu_selection = get_menu_selection();
        switch (menu_selection) {
            case 1:
                cout << "--------------------\n";
                cout << "Add a new Record\n";
                input_name = get_name();
                input_address = get_address();
                input_year = get_birth_year();
                input_phone = get_phone_number();
                records.add_record(input_name, input_address, input_year, input_phone);
                break;
            case 2:
                cout << "--------------------\n";
                cout << "Print Record(s) with the name\n";
                input_name = get_name();
                records.print_record(input_name,1);
                break;
            case 3:
                cout << "--------------------\n";
                cout << "Print Record(s) with the same phone number\n";
                input_phone = get_phone_number();
                records.print_record_phone(input_phone);
                break;
            case 4:
                cout << "--------------------\n";
<<<<<<< HEAD
                cout << "Print Record(s) with the same address\n";
                input_address = get_address();
                records.print_record_address(input_address);
                break;
            case 5:
                cout << "--------------------\n";
=======
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "Modify Record(s) with the same name\n";
                input_name = get_name();
                input_address = get_address();
                getline(cin, dummy);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break;
<<<<<<< HEAD
            case 6:
=======
            case 5:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Modify Record(s) with the same phone number\n";
                input_name = get_name();
                input_address = get_address();
                getline(cin, dummy);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break;
<<<<<<< HEAD
            case 7:
                cout << "--------------------\n";
                cout << "Modify Record(s) with the same address\n";
                input_name = get_name();
                input_address = get_address();
                getline(cin, dummy);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break;
            case 8:
=======
            case 6:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Printing Records...\n";
                records.print_all_records();
                break;
<<<<<<< HEAD
            case 9:
=======
            case 7:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Delete Record(s) with the same name\n";
                input_name = get_name();
                records.delete_record(input_name);
                break;
<<<<<<< HEAD
            case 11:
                cout << "--------------------\n";
                cout << "Delete Record(s) with the same address\n";
                input_address = get_address();
                records.delete_record_address(input_address);
                break;
            case 10:
=======
            case 8:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Delete Record(s) with the same phone number\n";
                input_phone = get_phone_number();
                records.delete_record_phone(input_phone);
                break;
<<<<<<< HEAD
            case 12:
=======
            case 9:
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
                cout << "--------------------\n";
                cout << "Reversing the order of all the Records...\n";
                records.reverse_llist();
                break;
        }
<<<<<<< HEAD
        if (menu_selection != 13) {
            display_commands();
        }
    } while (menu_selection != 13);
=======
        if (menu_selection != 10) {
            display_commands();
        }
    } while (menu_selection != 10);
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
    return;
}

void display_commands() {
    cout << "Usage:\n";
    cout << "\t1: Add a new record into the database.\n";
    cout << "\t2: Print information about a record using the name as the key. \n";
    cout << "\t3: Print information about a record using the phone number as the key. \n";
<<<<<<< HEAD
    cout << "\t4: Print information about a record using the address as the key. \n";
    cout << "\t5: Modify a record in the database using the name as the key. \n";
    cout << "\t6: Modify a record in the database using the phone number as the key. \n";
    cout << "\t7: Modify a record in the database using the address as the key. \n";
    cout << "\t8: Print all information in the database.\n";
    cout << "\t9: Delete an existing record from the database.\n";
    cout << "\t10: Delete an existing record from the database.\n";
    cout << "\t11: Delete an existing record from the database.\n";
	cout << "\t12: Reverse the order of all existing records from the database.\n";
    cout << "\t13: Quit the program.\n";
=======
    cout << "\t4: Modify a record in the database using the name as the key. \n";
    cout << "\t5: Modify a record in the database using the phone number as the key. \n";
    cout << "\t6: Print all information in the database.\n";
    cout << "\t7: Delete an existing record from the database using name as the key.\n";
    cout << "\t8: Delete an existing record from the database using phone nymber as the key.\n";
	cout << "\t9: Reverse the order of all existing records from the database.\n";
    cout << "\t10: Quit the program.\n";
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
    cout << "What would you like to do?\n";
    return;
}

int get_menu_selection() {
    int selection = 0;
    cin >> selection;
<<<<<<< HEAD
    while (cin.fail() || selection < 1 || selection > 13) {
        if (cin.fail()) {
            cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 13) {
=======
    while (cin.fail() || selection < 1 || selection > 10) {
        if (cin.fail()) {
            cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 10) {
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
            cout << "Not a valid choice.\n";
            display_commands();
        }
        cin.clear();
        cin.ignore(256, '\n');
        cin >> selection;
    }
    cin.clear();
    return selection;
}

string get_name() {
    string name = "";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter the person's NAME: ";
    getline(cin, name);
    return name;
}

string get_address() {
    string address = "";
    cout << "Please enter the person's ADDRESS (Enter '$' when you're finished):\n";
    getline(cin, address, '$');
    return address;
}

int get_birth_year() {
    int birth_year = 0;
    cout << "Please enter the person's BIRTH YEAR: ";
    cin >> birth_year;
    while (std::cin.fail()) {
        cout << "Not an integer, please enter an integer: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> birth_year;
    }
    cin.clear();
    cin.ignore(256, '\n');
    return birth_year;
}

string get_phone_number() {
    string phone_number = "";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter the contact's TELEPHONE NUMBER: ";
    getline(cin, phone_number);
    return phone_number;
}

string get_file_name() {
    string file_name = "";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter your FILE NAME ('.txt' file extension will be added): ";
    getline(cin, file_name);
    file_name += ".txt";
    return file_name;
}
