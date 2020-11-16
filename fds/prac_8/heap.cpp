#include <iostream>
using namespace std;

void reheap_iterative(int arr[], int i, int len)
{
	bool flag=true;
	while(flag && i>=0)
	{
		flag=false;
		if (2 * i > len)
			return;
		int left = 2 * i, right = 2 * i + 1;
		int local_max;
		if (right <= len)
		{
			local_max = (arr[left] > arr[right]) ? left : right;
		}
		else
		{
			local_max = left;
		}
		if (arr[local_max] > arr[i])
		{
			flag=true;
			int temp = arr[local_max];
			arr[local_max] = arr[i];
			arr[i] = temp;
			i=local_max;
		}
	}
}

void reheap(int arr[], int i, int len)
{
	if (2 * i > len)
		return;
	int left = 2 * i, right = 2 * i + 1;
	int local_max;
	if (right <= len)
	{
		local_max = (arr[left] > arr[right]) ? left : right;
	}
	else
	{
		local_max = left;
	}
	if (arr[local_max] > arr[i])
	{
		int temp = arr[local_max];
		arr[local_max] = arr[i];
		arr[i] = temp;
		reheap(arr, local_max, len);
	}
}

void heapify(int arr[], int len)
{
	for (int i = len / 2; i >= 1; i--)
	{
		reheap(arr, i, len);
	}
	int temp = arr[len];
	arr[len] = arr[1];
	arr[1] = temp;
	for (int i = 1; i <= len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void heap_sort(int arr[], int n)
{
	int count = 0;
	int times = n;
	while (times--)
	{
		heapify(arr, n - count);
		count++;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int n;
	cin >> n;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	heap_sort(arr, n);
}