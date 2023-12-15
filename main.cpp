#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int generateRandomNumber(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

template <typename T, size_t N>
void printArray(const T(&arr)[N]) 
{
    for (const auto& element : arr) 
    {
        cout << element << " ";
    }
    cout << endl;
}

template <typename T, size_t N>
T findMax(const T(&arr)[N]) 
{
    T maxVal = arr[0];
    for (size_t i = 1; i < N; ++i) 
    {
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T, size_t Rows, size_t Cols>
T findMax(const T(&arr)[Rows][Cols]) 
{
    T maxVal = arr[0][0];
    for (size_t i = 0; i < Rows; ++i) 
    {
        for (size_t j = 0; j < Cols; ++j) 
        {
            if (arr[i][j] > maxVal) 
            {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

template <typename T, size_t Dim1, size_t Dim2, size_t Dim3>
T findMax(const T(&arr)[Dim1][Dim2][Dim3]) 
{
    T maxVal = arr[0][0][0];
    for (size_t i = 0; i < Dim1; ++i) 
    {
        for (size_t j = 0; j < Dim2; ++j) 
        {
            for (size_t k = 0; k < Dim3; ++k) 
            {
                if (arr[i][j][k] > maxVal) 
                {
                    maxVal = arr[i][j][k];
                }
            }
        }
    }
    return maxVal;
}

template <typename T>
T findMax(const T& a, const T& b) 
{
    return (a > b) ? a : b;
}

template <typename T>
T findMax(const T& a, const T& b, const T& c) 
{
    return findMax(findMax(a, b), c);
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(0)));
    const size_t arrSize = 10;
    int arr[arrSize];
    for (size_t i = 0; i < arrSize; ++i) 
    {
        arr[i] = generateRandomNumber(1, 100);
    }
    cout << "Одновимірний масив: ";
    printArray(arr);
    cout << "Максимальне значення: " << findMax(arr) << endl;
    const size_t rows = 3;
    const size_t cols = 4;
    int matrix[rows][cols];
    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < cols; ++j) 
        {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
    cout << "\nДвовимірний масив:\n";
    for (size_t i = 0; i < rows; ++i) 
    {
        printArray(matrix[i]);
    }
    cout << "Максимальне значення: " << findMax(matrix) << endl;
    const size_t dim1 = 2;
    const size_t dim2 = 3;
    const size_t dim3 = 4;
    int array3D[dim1][dim2][dim3];
    for (size_t i = 0; i < dim1; ++i) 
    {
        for (size_t j = 0; j < dim2; ++j) 
        {
            for (size_t k = 0; k < dim3; ++k) 
            {
                array3D[i][j][k] = generateRandomNumber(1, 100);
            }
        }
    }
    cout << "\nТривимірний масив:\n";
    for (size_t i = 0; i < dim1; ++i) 
    {
        for (size_t j = 0; j < dim2; ++j) 
        {
            printArray(array3D[i][j]);
        }
        cout << endl;
    }
    cout << "Максимальне значення: " << findMax(array3D) << endl;
    int x = generateRandomNumber(1, 100);
    int y = generateRandomNumber(1, 100);
    int z = generateRandomNumber(1, 100);
    cout << "\nДва цілих числа: " << x << ", " << y << endl;
    cout << "Максимальне значення: " << findMax(x, y) << endl;
    cout << "\nТри цілих числа: " << x << ", " << y << ", " << z << endl;
    cout << "Максимальне значення: " << findMax(x, y, z) << endl;
    return 0;
}
