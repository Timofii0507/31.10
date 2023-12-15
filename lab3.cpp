#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

template <typename T>
bool isPrime(T n) 
{
    if (n < 2) return false;
    for (T i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) return false;
    }
    return true;
}

template <typename T>
int countPrimes(T arr[], int size) 
{
    int count = 0;
    cout << "Масив: [";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i]; 
        if (i < size - 1) cout << ", ";
        if (isPrime(arr[i])) count++;
    }
    cout << "]\n";
    return count;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int N = 10;
    int arr[N]; 
    for (int i = 0; i < N; i++) 
    {
        arr[i] = rand() % 10; 
    }
    int primes = countPrimes(arr, N); 
    cout << "Кількість простих чисел: " << primes << "\n"; 
    return 0;
}
