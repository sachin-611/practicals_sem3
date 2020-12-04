#include <string>
#ifndef RECORD_H
#define RECORD_H
using namespace std;
struct record {
    string name;
    string address;
    int birth_year;
    string phone_number;
    struct record* next;
};
#endif
