#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // директива підключення заголовочного файлу для роботи з форматуванням виведення
#include <Windows.h>

using namespace std;

template <typename T>
void initializeMatrix(T** matrix, int size) 
{
    srand(time(0));
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            matrix[i][j] = rand() % 10;  
        }
    }
}

template <typename T>
void printMatrix(T** matrix, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void findDiagonalMinMax(T** matrix, int size, T& maxElement, T& minElement) 
{
    maxElement = matrix[0][0];
    minElement = matrix[0][0];
    for (int i = 1; i < size; ++i) 
    {
        if (matrix[i][i] > maxElement) 
        {
            maxElement = matrix[i][i];
        }
        if (matrix[i][i] < minElement) 
        {
            minElement = matrix[i][i];
        }
    }
}

template <typename T>
void sortRows(T** matrix, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size - 1; ++j) 
        {
            for (int k = 0; k < size - j - 1; ++k) 
            {
                if (matrix[i][k] > matrix[i][k + 1]) 
                {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 3;
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i) 
    {
        intMatrix[i] = new int[size];
    }
    initializeMatrix(intMatrix, size);
    cout << "Цілочисельна матриця:" << endl;
    printMatrix(intMatrix, size);
    int maxInt, minInt;
    findDiagonalMinMax(intMatrix, size, maxInt, minInt);
    cout << "Максимальний елемент на головній діагоналі: " << maxInt << endl;
    cout << "Мінімальний елемент на головній діагоналі: " << minInt << endl;
    sortRows(intMatrix, size);
    cout << "Відсортована ціла матриця: " << endl;
    printMatrix(intMatrix, size);
    for (int i = 0; i < size; ++i) 
    {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;
    return 0;
}
