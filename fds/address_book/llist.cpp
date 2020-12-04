#include <iostream>
#include <fstream>
#include <string>
#include "record.h"
#include "llist.h"
#include "address_book.h"
using namespace std;
llist::llist() {
    int records_read = 0;
    start = NULL;
    file_name = "save.txt";

    records_read = read_file();
    if (records_read < 0) {
        cout << "'" << file_name << " was not found.\n";
        cout << "Therefore, no records have been added to the list and '" << file_name << "' will be created.\n";
    } else if (records_read == 0) {
        cout << "'" << file_name << "' has been found but is empty.\n";
        cout << "Therefore, no records have been added to the database.\n";
    } else {
        cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    }
    cout << "--------------------\n";
}

llist::llist(string file) {
    int records_read = 0;
    start = NULL;
    file_name = file;

    records_read = read_file();
    if (records_read < 0) {
        cout << "'" << file_name << " was not found.\n";
        cout << "Therefore, no records have been added to the list and '" << file_name << "' will be created.\n";
    } else if (records_read == 0) {
        cout << "'" << file_name << "' has been found but is empty.\n";
        cout << "Therefore, no records have been added to the database.\n";
    } else {
        cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    }
    cout << "--------------------\n";
}

llist::~llist() {
    write_file();
    delete_all_records();
}

int llist::read_file() {
    ifstream read_file(file_name.c_str());
    struct record *temp = NULL;
    struct record *index = NULL;
    struct record *previous = NULL;
    int file_char_length = 0;
    int record_count = 0;
    string dummy = "";

    if (!read_file.is_open()) {
        read_file.close();
        return -1;
    }
    read_file.seekg(0, read_file.end);
    file_char_length = read_file.tellg();
    if (file_char_length == 0) {
        read_file.close();
        return 0;
    }
    read_file.seekg(0, read_file.beg);
    do {
        string address = "";

        temp = new record;
        index = start;
        getline(read_file, temp->name);
        getline(read_file, temp->address, '$');
        read_file >> temp->birth_year;
        getline(read_file, dummy);
        getline(read_file, temp->phone_number);
        getline(read_file, dummy);
        ++record_count;
        while (index != NULL) {
            previous = index;
            index = index->next;
        }
        if (previous == NULL) {
            temp->next = start;
            start = temp;
        } else {
            previous->next = temp;
            temp->next = index;
        }
    } while (!read_file.eof());
    read_file.close();
    return record_count;
}

int llist::write_file() {
    ofstream write_file(file_name.c_str());
    record *index = start;
    int record_count = 0;

    if (start == NULL) {
        cout << "The database is empty. Therefore, no records have been added to file: " << file_name << '\n';
        write_file.close();
        return -1;
    }
    do {
        write_file << index->name << "\n";
        write_file << index->address << "$" << "\n";
        write_file << index->birth_year << "\n";
        if (index->next != NULL) {
            write_file << index->phone_number << "\n\n";
        } else {
            write_file << index->phone_number << "\n";
        }
        index = index->next;
        ++record_count;
    } while (index != NULL);
    cout << record_count << " records have been recorded to file: " << file_name << "\n";
    write_file.close();
    return 0;
}

void llist::delete_all_records() {
    struct record *temp = start;
    struct record *index = NULL;
    int records_deleted = 0;
    cout << "--------------------\n";
    if (start != NULL) {
        while (index != NULL) {
            temp = index;
            index = index->next;
            start = index;
            delete temp;
            ++records_deleted;
        }
        cout << records_deleted << " records removed from the memory.\n";
    } else {
        cout << "The Database is empty. Therefore, no records have been removed.\n";
    }
    cout << "--------------------\n";
    return;
}

int llist::add_record(string input_name, string input_address, int input_birth_year, string input_phone_number) {
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;
    temp = new record;
    temp->name = input_name;
    temp->address = input_address;
    temp->birth_year = input_birth_year;
    temp->phone_number = input_phone_number;
    while (index != NULL) {
        previous = index;
        index = index->next;
    }
    if (previous == NULL) {
        temp->next = start;
        start = temp;
    } else {
        previous->next = temp;
        temp->next = index;
    }
    cout << "--------------------\n";
    cout << "Record has been added.\n";
    cout << "--------------------\n";
    return 1;
}

int llist::print_record(string input_name) {
    struct record *index = start;
    int records_printed = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_name == index->name) {
            ++records_printed;
            cout << "====================\n";
            cout << "Record #" << records_printed << " of:\n";
            cout << "Name: " << index->name << "\n";
            cout << "Address: " << index->address << '\n';
            cout << "Year of Birth: " << index->birth_year << '\n';
            cout << "Telephone Number: " << index->phone_number << '\n';
        }
        index = index->next;
    }

    if (records_printed == 0) {
        cout << "No records of " << input_name << " found.\n";
    } else {
        cout << records_printed << " records of " << input_name << " printed." << '\n';
    }
    cout << "--------------------\n";
    return 1;
}

int llist::modify_record(string input_name, string input_address, string input_phone_number) {

    struct record *index = start;
    int records_modified = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_name == index->name) {
            index->address = input_address;
            index->phone_number = input_phone_number;
            ++records_modified;
        }
        index = index->next;
    }
    if (records_modified == 0) {
        cout << "No records of " << input_name << " found.\n";
    } else {
        cout << records_modified << " records of " << input_name << " records_modified.\n";
    }
    cout << "--------------------\n";
    return 1;
}

void llist::print_all_records() {
    struct record *index = start;
    int record_count = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records have been _printed.\n";
        cout << "--------------------\n";
        return;
    }
    while (index != NULL) {
        ++record_count;
        cout << "====================\n";
        cout << "Record #" <<  record_count << '\n';
        cout << "Name: " <<  index->name << '\n';
        cout << "Address: " <<  index->address << '\n';
        cout << "Year of Birth: " << index->birth_year << '\n';
        cout << "Telephone Number: " << index->phone_number << '\n';
        index = index->next;
    }
    cout << record_count << " Records printed.\n";
    cout << "--------------------\n";
    return;
}

int llist::delete_record_address(string input_address) {
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;
    int records_deleted = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_address << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_address == index->address) {
            temp = index;
            if (index == start) {
                index = index->next;
                start = index;
            } else {
                index = index->next;
                previous->next = index;
            }
            delete temp;
            ++records_deleted;
        } else {
            previous = index;
            index = index->next;
        }
    }
    if (records_deleted == 0) {
        cout << "No records of " << input_address << " found.\n";
    } else {
        cout << records_deleted << " records of " << input_address << " records_deleted.\n";
    }
    cout << "--------------------\n";
    return 1;
}

int llist::delete_record(string input_name) {
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;
    int records_deleted = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_name == index->name) {
            temp = index;
            if (index == start) {
                index = index->next;
                start = index;
            } else {
                index = index->next;
                previous->next = index;
            }
            delete temp;
            ++records_deleted;
        } else {
            previous = index;
            index = index->next;
        }
    }
    if (records_deleted == 0) {
        cout << "No records of " << input_name << " found.\n";
    } else {
        cout << records_deleted << " records of " << input_name << " records_deleted.\n";
    }
    cout << "--------------------\n";
    return 1;
}

int llist::delete_record_phone(string input_phone) {
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;
    int records_deleted = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_phone << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_phone == index->phone_number) {
            temp = index;
            if (index == start) {
                index = index->next;
                start = index;
            } else {
                index = index->next;
                previous->next = index;
            }
            delete temp;
            ++records_deleted;
        } else {
            previous = index;
            index = index->next;
        }
    }
    if (records_deleted == 0) {
        cout << "No records of " << input_phone << " found.\n";
    } else {
        cout << records_deleted << " records of " << input_phone << " records_deleted.\n";
    }
    cout << "--------------------\n";
    return 1;
}

int llist::print_record_phone(string input_phone) {
    struct record *index = start;
    int records_printed = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_phone << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_phone == index->phone_number) {
            ++records_printed;
            cout << "====================\n";
            cout << "Record #" << records_printed << " of:\n";
            cout << "Name: " << index->name << "\n";
            cout << "Address: " << index->address << '\n';
            cout << "Year of Birth: " << index->birth_year << '\n';
            cout << "Telephone Number: " << index->phone_number << '\n';
        }
        index = index->next;
    }

    if (records_printed == 0) {
        cout << "No records of " << input_phone << " found.\n";
    } else {
        cout << records_printed << " records of " << input_phone << " printed." << '\n';
    }
    cout << "--------------------\n";
    return 1;
}

int llist::print_record_address(string input_address) {
    struct record *index = start;
    int records_printed = 0;

    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records of " << input_address << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while (index != NULL) {
        if (input_address == index->address) {
            ++records_printed;
            cout << "====================\n";
            cout << "Record #" << records_printed << " of:\n";
            cout << "Name: " << index->name << "\n";
            cout << "Address: " << index->address << '\n';
            cout << "Year of Birth: " << index->birth_year << '\n';
            cout << "Telephone Number: " << index->phone_number << '\n';
        }
        index = index->next;
    }

    if (records_printed == 0) {
        cout << "No records of " << input_address << " found.\n";
    } else {
        cout << records_printed << " records of " << input_address << " printed." << '\n';
    }
    cout << "--------------------\n";
    return 1;
}

void llist::reverse_llist() {
    cout << "--------------------\n";
    if (start == NULL) {
        cout << "The Database is empty. Therefore, no records can be reverse_llist.\n";
    } else if (start->next == NULL) {
        cout << "Only one record exists in the database.\n";
    } else {
        reverse_llist(start);
        cout << "All Records have been reversed.\n";
    }
    cout << "--------------------\n";
    return;
}

record* llist::reverse_llist(record *index) {
    record *rev=NULL;

    while(index!=NULL)
    {
        record *temp=rev;
        rev=index;
        index=index->next;
        rev->next=temp;
    }
    start=rev;
    return rev;
}
