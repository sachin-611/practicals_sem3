#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    string name;
    Node(int data, string inp)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
        this->name = inp;
    }
};

class Double_LL
{

public:
    Node *head;
    int size;

    Double_LL() { head = NULL; }

    void insert(int element, string inp)
    {
        size++;
        Node *newNode = new Node(element, inp);
        if (head == NULL)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node *tail = head->prev;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
    }

    void delete_Node(int key)
    {
        if (head == NULL)
        {
            return;
        }
        Node *curr = head;
        Node *previs = NULL;
        size--;
        while (curr->data != key)
        {
            if (curr->next == head)
            {
                cout << "Does not exist" << endl;
                return;
            }
            previs = curr;
            curr = curr->next;
        }

        if (curr->next == head && previs == NULL)
        {
            head = NULL;
            free(curr);
            return;
        }

        if (curr == head)
        {
            previs = head->prev;
            head = head->next;
            previs->next = head;
            head->prev = previs;
            free(curr);
        }
        else if (curr->next == head)
        {
            previs->next = head;
            head->prev = previs;
            free(curr);
        }
        else
        {
            Node *temp = curr->next;
            previs->next = temp;
            temp->prev = previs;
            free(curr);
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->name << "(" << temp->data << ")"
                 << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    int getSize()
    {
        return size;
    }

    void roundrobin(int per)
    {
        if (head == NULL)
        {
            cout << "The list is empty you cannot perform operations" << endl;
            return;
        }
        display();
        cout << "ROUND ROBIN IN PROCESS:- " << endl;
        while (!isEmpty())
        {
            Node *temp = head;
            int cnt = getSize();
            int flag = 0;
            while (cnt--)
            {
                temp->data -= per;
                if (temp->data > 0)
                {
                    cout << temp->name << "(" << temp->data << ")"
                         << " ";
                    temp = temp->next;
                    flag = 1;
                }
                else
                {
                    Node *del = temp;
                    if (temp->next == temp)
                    {
                        cout << "\nJOB ROUND ROBIN COMPLETED" << endl;
                        temp = NULL;
                    }
                    temp = temp->next;

                    delete_Node(del->data);
                }

                if (temp == NULL)
                {
                    cout << endl;
                    cout << endl;
                }
                flag = 0;
            }
            if (temp == NULL)
            {
                break;
            }
        }
    }
};

int main()
{

    Double_LL o1;
    cout << "Enter no of processes :- ";
    int n;
    cin >> n;
    cout << "Enter time bust for the processes:- ";
    int b;
    cin >> b;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of process name:- ";
        string inp;
        cin >> inp;
        cout << "Enter time vale:- ";
        int x;
        cin >> x;
        o1.insert(x, inp);
    }
    o1.roundrobin(b);
    return 0;
}