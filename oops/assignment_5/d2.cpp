#include<bits/stdc++.h>

using namespace std;

template <class T>
class selection_sort
{
    int size;
    T arr[100];
public:
    void get_data();
    void display();
    void sort_algorithm();
};

template<class T>
void selection_sort<T>::get_data()
{
    cout<<"\n Enter the size of the array : ";
    cin>>size;
    cout<<"\n Enter the elements of the array : ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
}

template<class T>
void selection_sort<T>::display()
{
    cout<<"\n\t Array is :: ";
    for(int i = 0; i < size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template<class T>
void selection_sort<T>::sort_algorithm()
{
    for(int i = 0; i < size; i++)
    {
        int max_index = i;
        for(int j = i; j < size; j++)
        {
            if(arr[j] > arr[max_index])
                max_index = j;
        }
        swap(arr[i], arr[max_index]);
    }
}

int main()
{
    selection_sort<int> int_obj;
    selection_sort<float> float_obj;
    selection_sort<char> char_obj;

    cout<<"\n For integer data type --> \n";
    int_obj.get_data();
    cout<<"\n After Sorting :: ";
    int_obj.sort_algorithm();
    int_obj.display();

    cout<<"\n For float data type --> \n";
    float_obj.get_data();
    cout<<"\n After Sorting :: ";
    float_obj.sort_algorithm();
    float_obj.display();

    cout<<"\n For character data type --> \n";
    char_obj.get_data();
    cout<<"\n After Sorting :: ";
    char_obj.sort_algorithm();
    char_obj.display();
    return 0;
} 
