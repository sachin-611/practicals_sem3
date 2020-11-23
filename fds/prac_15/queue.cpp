#include <iostream>
using namespace std;

class Queue {
	int size, front, rear;
	int* arr;
public:
	Queue(int n = 1000) {
		size = n;
		front = -1;
		rear = -1;
		arr = new int [size];
	}

	~Queue()
	{
		delete []arr;
	}

	void display() {
		if (empty()) {
			cout << "Queue is empty!!" << endl;
			return;
		}
		cout << "Queue:- ";
		for (int i = front + 1; i <= rear; i++) {
			cout << arr[i] << flush;
			if (i < rear) {
				cout << " " << flush;
			}
		}
		cout << endl;
	}


	bool empty() {
		return front == rear;
	}

	bool full() {
		return rear == size - 1;
	}

	void enqueue(int x) {
		if (full()) {
			cout << "Queue is full Cannot enqueue!!" << endl;
			return;
		}
		arr[++rear] = x;
	}

	int dequeue() {
		int x = -1;
		if (empty()) {
			cout << "Queue is empty cannot perform dequeue!!" << endl;
			return;
		}
		return arr[++front];
	}
};

int main() {

	int n;
	cout << "Enter number of elements:- ";
	cin >> n;
	Queue q1(n);
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Enter " << i + 1 << " element:- ";
		cin >> num;
		q1.enqueue(num);
	}
	q1.display();
	cout << "After deleting :- " << endl;
	for (int i = 0; i < x; i++) {
		q1.dequeue();
	}
	q1.display();

	return 0;
}