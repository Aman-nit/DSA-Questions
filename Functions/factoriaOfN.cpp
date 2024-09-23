#include <iostream>
using namespace std;

int factorialOfN(int n)
{
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    int factorial = factorialOfN(n);
    cout << "Factorial of " << n << " is : " << factorial << endl;
}