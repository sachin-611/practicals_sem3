#include <iostream>

using namespace std;

class Queue {
    int size, front, rear;
    int* arr;
public:
    Queue(int n = 10) {
        size = n;
        front = 0;
        rear = 0;
        arr = new int [size];
    }
    ~Queue() {
        delete [] arr;
    }

    bool empty() {
        return (front == rear);
    }

    bool full() {
        return (front == (rear + 1) % size);
    }

    void enqueue(int x) {
        if (full()) {
            cout << "Queue is full cannot insert" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    int dequeue() {
        if (empty()) {
            cout << "Queue is empty returning -1!!" << endl;
            return -1;
        }
        front = (front + 1) % size;
        return arr[front];
    }

    void display() {
        if (empty()) {
            cout << "Queue is empty!!" << endl;
            return;
        }
        cout << "Queue is :- ";
        int i = front + 1;
        while (i != (rear + 1) % size)
        {
            cout << arr[i] << flush;
            if (i < rear) {
                cout << " " << flush;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }

    void display_full_array()
    {
        cout << endl;
        for (int i = 0; i < size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

void display_menu()
{
    cout << "\nQUEUE !!" << endl;
    cout << "1. enqueue" << endl;
    cout << "2. dequeue" << endl;
    cout << "3. display" << endl;
    cout << "4. display whole array" << endl;
    cout << "5. exit" << endl;
}

int main() {
    Queue q1(20);
    while (1)
    {
        display_menu();
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Element : ";
            int val; cin >> val;
            q1.enqueue(val);
        }
        else if (choice == 2)
        {
            q1.dequeue();
        }
        else if (choice == 3)
        {
            q1.display();
        }
        else if (choice == 4)
        {
            q1.display_full_array();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "invalid choice!!" << endl;
        }
    }
    return 0;
}