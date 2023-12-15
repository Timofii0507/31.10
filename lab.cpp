#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void min_max(T* arr, size_t size, T& min, T& max, int& min_index, int& max_index)
{
    min = arr[0];
    max = arr[0];
    min_index = 0;
    max_index = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 1, 5, 3, 2, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    int min_index, max_index;
    min_max(arr, size, min, max, min_index, max_index);
    cout << "̳Мінімальне значення: " << min << " (індекс: " << min_index << ")" << endl;
    cout << "Максимальне значення: " << max << " (індекс: " << max_index << ")" << endl;
    return 0;
}