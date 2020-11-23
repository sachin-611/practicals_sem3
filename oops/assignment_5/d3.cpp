#include <bits/stdc++.h>
using namespace std;

template <class T>
class quick_sort
{
public:
    T arr[100];
    int size;
    void quick_sort<T>::get_data()
    {
        cout << "\n Enter the size of the array : ";
        cin >> size;
        cout << "\n Enter the elements of the array : ";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }
    void quick_sort<T>::display()
    {
        cout << "\n\t Array is :: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int quick_sort<T>::partition(T arr[], int low, int high)
    {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quick_sort<T>::sort_algorithm(T arr[], int low, int high)
    {
        if (low < high)
        {
            int part_index = partition(arr, low, high);

            sort_algorithm(arr, low, part_index - 1);
            sort_algorithm(arr, part_index + 1, high);
        }
    }
};

int main()
{
    quick_sort<int> int_obj;
    quick_sort<float> float_obj;
    quick_sort<char> char_obj;

    cout << "\n For integer data type --> \n";
    int_obj.get_data();
    cout << "\n After Sorting :: ";
    int_obj.sort_algorithm(int_obj.arr, 0, int_obj.size);
    int_obj.display();

    cout << "\n For float data type --> \n";
    float_obj.get_data();
    cout << "\n After Sorting :: ";
    float_obj.sort_algorithm(float_obj.arr, 0, float_obj.size);
    float_obj.display();

    cout << "\n For character data type --> \n";
    char_obj.get_data();
    cout << "\n After Sorting :: ";
    char_obj.sort_algorithm(char_obj.arr, 0, char_obj.size);
    char_obj.display();
    return 0;
}
