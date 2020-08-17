#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n - 1 == 0) return 1;
    else return n * factorial(n - 1);   
}

int main()
{
    int number;
    cin >> number;
    
    int value = 1;
    if (number != 0) value = factorial(number);

    cout << value;
    return 0;
}