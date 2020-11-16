#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int PRN;
    string name;
    node * next;
};
int count_temp = 1;
class club : node
{
public:
    node *president, *sec;
    club()
    {
        president = NULL;
        sec = NULL;
    }
    ~club()
    {
        node * temp = president;
        node * t = new node;
        while(temp->next != NULL)
        {
            t = temp;
            temp = temp->next;
            delete t;
        }
        delete temp;
    }
    bool check_member(int temp_PRN)
    {
        if(president == NULL)
            return false;
        node *temp = president;
        while(temp->PRN != temp_PRN)
        {
            if(temp->next == NULL)
                return false;
            temp = temp->next;
        }
        return true;
    }
    void add_president_or_secretary()
    {
        if(president == NULL)
        {
            president = new node;
            cout<<"\n Enter the details of President :";
            cout<<"\n President's PRN --> ";
            cin>>president->PRN;
            cout<<"\t President's Name --> ";
            cin>>president->name;
            president->next = NULL;
            cout<<"\n President added !! \n";
        }

        if(sec == NULL)
        {
            sec = new node;
            cout<<"\n Enter the details of Secretary :";
            cout<<"\n Secretary's PRN --> ";
            cin>>sec->PRN;
            cout<<"\t Secretary's Name --> ";
            cin>>sec->name;
            sec->next = NULL;
            node * temp = president;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = sec;
            cout<<"\n Secretary added !!\n";
        }
    }
    void add_member()
    {
        node *member = new node;
        cout<<"\n Enter the details : ";
        cout<<"\n\t Member's PRN --> ";
        cin>>member->PRN;
        cout<<"\t Member's Name --> ";
        cin>>member->name;
        node *temp = new node;
        temp = president;
        while(temp->next != sec)
        {
            temp = temp->next;
        }
        temp->next = member;
        member->next = sec;
        cout<<"\n\t Member added !!\n";
    }
    void delete_()
    {
        if(president == NULL)
        {
            cout<<"\n Empty list !!";
            return;
        }
        int PRN_to_delete;
        cout<<"\n Enter the PRN of the member to be deleted : ";
        cin>>PRN_to_delete;

        node * t = new node;

        if(check_member(PRN_to_delete) == false)
        {
            cout<<"\n No member with given PRN present!!\n";
            return;
        }

        if(president->PRN == PRN_to_delete && president->next == NULL)
        {
            char continue_or_not;
            cout<<"\nDo You Want to delete complete list? (Y/N) ";
            cin>>continue_or_not;

            if(continue_or_not == 'N' || continue_or_not == 'n')
                return;

            t = president;
            delete t;
            president = NULL;
            cout<<"\n\t Exmpty list !!";
            return;
        }
        else if(president->PRN == PRN_to_delete && president->next != sec)
        {
            t = president;
            president = president->next;
            delete t;
            cout<<"\n\t President deleted !!\n";
            return;
        }
        else if(president->PRN == PRN_to_delete && president->next == sec)
        {
            t = president;
            president = sec;
            president->next = NULL;
            sec = NULL;
            delete t;
            cout<<"\n\t President deleted !!\n";
            return;
        }

        node *temp = president;
        while(temp->next->PRN != PRN_to_delete)
        {
            temp = temp->next;
            t = temp->next;
        }


        if(temp->next == sec && temp != president)
        {
            temp->next = NULL;
            sec = temp;
            cout<<"\n\t Secretary deleted !!\n";
        }
        else if(temp->next == sec && temp == president)
        {
            sec = NULL;
            president->next = NULL;
            cout<<"\n\t Secretary deleted !!\n";
        }
        else
        {
            temp->next = temp->next->next;
            cout<<"\n\t Member deleted !!\n";
        }
        delete t;
    }
    int total_mem()
    {
        int total_members = 0;
        node * temp = president;
        while(temp != NULL)
        {
            total_members += 1;
            temp = temp->next;
        }

        return(total_members);
    }
    void insert_at()
    {        
            int position;
            cout<<"\n Enter the position at which you want to enter the new member : ";
            cin>>position;
            if(position <= 0)
            {
                cout<<"\n Invalid Position !!\n";
                return;
            }
            if(position > total_mem() + 1)
            {
                cout<<"\n Index out of bound !!\n";
                return;
            }
            node * member = new node;
            cout<<"\n Enter Member's details : ";
            cout<<"\n\t PRN --> ";
            cin>>member->PRN;
            cout<<"\t Name --> ";
            cin>>member->name;
            member->next = NULL;

            if(position == 1)
            {
                member->next = president;
                president = member;
                cout<<"\n\t President Updated !!\n";
            }
            else if(position == total_mem() + 1)
            {
                node * temp = president;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = member;
                sec = member;
                cout<<"\n\t Secretary updated !!\n";
            }
            else
            {
                int count = 1;
                node * temp = president;
                while(position != count + 1)
                {
                    temp = temp->next;
                    count += 1;
                }
                member->next = temp->next;
                temp->next = member;
                cout<<"\n\t Member added !!\n";
            }
        }
    void display()
    {
        if(president == NULL)
        {
            cout<<"\n There are no members in the club yet!! \n";
            return;
        }
        cout<<"\n -x-x-x- Display CLUB -x-x-x-";
        node *temp = new node;
        cout<<"\n President :: ";
        cout<<"\n\t PRN --> "<<president->PRN;
        cout<<"\n\t Name --> "<<president->name;
        temp = president->next;
        int count = 1;
        while(temp != sec && temp!=NULL)
        {
            cout<<"\n Member "<<count<<" :: ";
            cout<<"\n\t PRN --> "<<temp->PRN;
            cout<<"\n\t Name --> "<<temp->name;
            temp = temp->next;
            count += 1;
        }
        if(temp != NULL)
        {
        cout<<"\n Secretary : ";
        cout<<"\n\t PRN --> "<<temp->PRN;
        cout<<"\n\t Name --> "<<temp->name;
        }

        cout<<"\n -x-x-x-x-x-x-\n";
    }
    void reverse_list(node * head)
    {
        if(head == president)
        {
            if(head->next != NULL)
                reverse_list(head->next);
            cout<<"\n Secretary : ";
            cout<<"\n\t PRN --> "<<head->PRN;
            cout<<"\n\t Name --> "<<head->name;
        }
        else if(head != sec && head != president)
        {
            if(head->next != NULL)
                reverse_list(head->next);
            cout<<"\n Member "<<count_temp<<" : ";
            cout<<"\n\t PRN --> "<<head->PRN;
            cout<<"\n\t Name --> "<<head->name;
            count_temp += 1;
        }
        else if(head == sec)
        {
            cout<<"\n President :";
            cout<<"\n\t PRN --> "<<head->PRN;
            cout<<"\n\t Name --> "<<head->name;
        }
    }

    void operator=(const club &obj)
    {
        if(obj.president == NULL)
        {
            node * temp = president;
            node * t = temp;
            while(t != NULL && t->next != NULL)
            {
                t = temp;
                temp = temp->next;
                delete t;
            }
            president = NULL;
            sec = NULL;
        }
        else
        {
            if(president == NULL)
            {
                president = new node;
                president->PRN = obj.president->PRN;
                president->name = obj.president->name;

                sec = new node;
                if(obj.sec != NULL)
                {
                    sec->PRN = obj.sec->PRN;
                    sec->name = obj.sec->name;
                    sec->next = NULL;
                    president->next = sec;
                }
                else
                {
                    sec = NULL;
                    president->next = sec;

                }
            }
            else
            {
                president->PRN = obj.president->PRN;
                president->name = obj.president->name;

                if(obj.sec != NULL && sec != NULL)
                {
                    sec->PRN = obj.sec->PRN;
                    sec->name = obj.sec->name;
                    sec->next = NULL;
                }
                else if(obj.sec != NULL && sec == NULL)
                {
                    sec = new node;
                    sec->PRN = obj.sec->PRN;
                    sec->name = obj.sec->name;
                    sec->next = NULL;

                    node * temp = president;
                    while(temp->next != NULL)
                        temp = temp->next;
                    temp->next = sec;
                }
                else if(obj.sec == NULL && sec != NULL)
                {
                    node * temp = president;
                    while(temp->next != sec)
                        temp = temp->next;
                    sec = NULL;
                    temp->next = sec;
                }
            }
        }
    }

    void operator+(const club &obj)
    {
        if(president == NULL)
        {
            cout<<"\n No members in the Pinnacle Club yet !!\n";
            return;
        }
        node * temp_A = this->president;
        cout<<"\n President : ";
        cout<<"\n\t PRN --> "<<temp_A->PRN;
        cout<<"\n\t Name --> "<<temp_A->name;

        int count = 1;
        while(temp_A->next != NULL && temp_A->next != this->sec)
        {
            temp_A = temp_A->next;
            cout<<"\n Member "<<count<<" : ";
            cout<<"\n\t PRN --> "<<temp_A->PRN;
            cout<<"\n\t Name --> "<<temp_A->name;
            count += 1;
        }

        node * temp_B = obj.president;
        while(temp_B->next != NULL && temp_B->next != obj.sec )
        {
            temp_B = temp_B->next;
            cout<<"\n Member "<<count<<" :: ";
            cout<<"\n\t PRN --> "<<temp_B->PRN;
            cout<<"\n\t Name --> "<<temp_B->name;
            count += 1;
        }

        if(sec != NULL)
        {
            cout<<"\n Secretary :: ";
            cout<<"\n\t PRN --> "<<temp_B->next->PRN;
            cout<<"\n\t Name --> "<<temp_B->next->name;
        }
    }

};

int main()
{
    club listA,listB;
    cout<<"\n-x-x-x- WELCOME TO CLUB -x-x-x-\n";
    while(1)
    {
        int choiced, choice_op;
        cout<<"\n Choose from the following : ";
        cout<<"\n 1 List A ";
        cout<<"\n 2 List B ";
        cout<<"\n 3 Concatenate List  ";
        cout<<"\n 4 Exit \n ";
        cin>>choiced;
        switch(choiced)
        {
        case 1:
            cout<<"\n -x-x-x- List A -x-x-x- \n";
            do
            {
                cout<<"\n Choose Operation:";
                cout<<"\n 1) Add \n 2) Delete ";
                cout<<"\n 3) Display Members \n 4) Insert at";
                cout<<"\n 5) Reverse the list \n 6) Total Number of Members";
                cout<<"\n 7) Exit \n";
                cin>>choice_op;
                switch(choice_op)
                {
                    case 1: if(listA.president == NULL || listA.sec == NULL)
                            {
                                listA.add_president_or_secretary();
                                listB = listA;
                            }
                            else
                            {
                                listA.add_member();
                            }
                            break;
                    case 2: listA.delete_();
                            break;
                    case 3: listA.display();
                            break;
                    case 4: listA.insert_at();
                            listB = listA;
                            break;
                    case 6: cout<<"\n The Club has "<<listA.total_mem()
                                <<" number of members (including President and Secretary) from Division A .\n";
                            break;
                    case 5: if(listA.president == NULL)
                            {
                                cout<<"\n No members Present !!\n";
                                break;
                            }
                            listA.reverse_list(listA.president);
                            count_temp = 1;
                            break;
                    case 7: break;
                    default: cout<<"\nInvalid entry !! \n";
                }
                if(choice_op != 7)
                    cout<<"\n";
            }while(choice_op != 7);
            cout<<"\n back to main menu \n";
            break;

        case 2:
            cout<<"\n -x-x-x- List B -x-x-x- \n";
            do
            {
                cout<<"\n Choose Operation:";
                cout<<"\n 1) Add ";
                cout<<"\n 2) Delete ";
                cout<<"\n 3) Display Members ";
                cout<<"\n 4) Insert at";
                cout<<"\n 5) Reverse the list ";
                cout<<"\n 6) Total Number of Members";
                cout<<"\n 7) Exit \n";
                cin>>choice_op;
                switch(choice_op)
                {
                    case 1: if(listB.president == NULL || listB.sec == NULL)
                            {
                                listB.add_president_or_secretary();
                                listA = listB;
                            }
                            else
                            {
                                listB.add_member();
                            }
                            break;
                    case 2: listB.delete_();
                            break;
                    case 3: listB.display();
                            break;
                    case 4: listB.insert_at();
                            listA = listB;
                            break;
                    case 6: cout<<"\n The Club has "<<listB.total_mem()
                                <<" number of members (including President and Secretary) from Division A .\n";
                            break;
                    case 5: if(listA.president == NULL)
                            {
                                cout<<"\n No members !!\n";
                                break;
                            }
                            listB.reverse_list(listB.president);
                            count_temp = 1;
                            break;
                    case 7: break;
                    default: cout<<"\nInvalid entry !! \n";
                }
                if(choice_op != 7)
                    cout<<"\n";
            }while(choice_op != 7);
            cout<<"\n back to main menu \n";
            break;

        case 3:
            cout<<"\n -x-x-x- CONCATENATED LIST -x-x-x- \n";
            listA + listB;
            cout<<"\n";
            break;
        case 4:
            cout<<"\nExited ";
            exit(0);
            break;
        default:
            cout<<"\n Invalid entry !! \n";
        }
    }

    return 0;
}
