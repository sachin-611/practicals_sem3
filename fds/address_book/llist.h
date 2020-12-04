#ifndef LLIST_H
#define LLIST_H
#include <string>
using namespace std;
class llist {
    private:
        record *start;
        string file_name;
        int read_file();
        int write_file();
        record* reverse_llist(record *);
        void delete_all_records();

    public:
        llist();
        llist(string);
        ~llist();
        int add_record(string, string, int, string);
        int print_record(string);
<<<<<<< HEAD
        int print_record(string,int);
        int print_record_address(string);
        int print_record_phone(string);
=======
        int print_record_phone(string);
        int print_record_address(string);
>>>>>>> bf94320c3d51a1afa704530c311ae5a79bf0105a
        int modify_record(string, string, string);
        int delete_record_phone(string);
        void print_all_records();
        int delete_record_address(string);
        int delete_record(string);
        int delete_record_address(string);
        int delete_record_phone(string);
        void reverse_llist();
};
#endif
