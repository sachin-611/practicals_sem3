#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
	int *arr;
	int len, size;
public:
	PriorityQueue(int n = 100)
	{
		size = n;
		len = 0;
		arr = new int[size];
	}
	~PriorityQueue()
	{
		delete []arr;
	}
	void heapify(int index)
	{
		int largest = index;
		if (2 * index <= len && arr[2 * index] > arr[largest])
		{
			largest = 2 * index;
		}
		if (2 * index + 1 <= len && arr[2 * index + 1] > arr[largest])
		{
			largest = 2 * index + 1;
		}
		if (largest != index)
		{
			swap(arr[largest], arr[index]);
			heapify(largest);
		}
	}
	int getLatest()
	{
		if (empty())
		{
			cout << "Heap is empty returning -1" << endl;
			return -1;
		}
		int maxi = arr[1];
		swap(arr[1], arr[len]);
		len--;
		if (len != 0)
			heapify(1);
		return maxi;
	}
	bool full()
	{
		return len == size;
	}
	bool empty()
	{
		return len == 0;
	}
	void insert(int data)
	{
		if (full())
		{
			cout << "Priority Queue is full cannot insert!!" << endl;
			return;
		}
		len++;
		arr[len] = data;
		int i = len;
		while (i > 1 && arr[i / 2] < arr[i])
		{
			swap(arr[i / 2], arr[i]);
			i = i / 2;
		}
	}
	void display()
	{
		for (int i = 1; i <= len; i++)
		{
			cout << arr[i] << " ";
		}
		cout << " ";
	}
};

void menu()
{
	cout << "\n1. Add element\n";
	cout << "2. Remove\n";
	cout << "3. Display\n";
	cout << "3. Exit\n";
	cout << "Enter your choice : ";
}

int main()
{
	PriorityQueue p1;
	while (1)
	{
		menu();
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			int value;
			cout << "Enter the value you want to add to the Queue : ";
			cin >> value;
			p1.insert(value);
		}
		else if (ch == 2)
		{
			cout << "The value remove from Queue is : ";
			cout << p1.getLatest() << "\n";
		}
		else if (ch == 3)
		{
			p1.display();
		}
		else if (ch == 4)
		{
			break;
		}
		else
		{
			cout << "Invalid choice\n";
		}
	}

	return 0;
}