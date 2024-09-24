#include <iostream>
using namespace std;

bool isPrimeOrNot(int n)
{
    if (n <= 1)
    {

        return false;
    }
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    if (isPrimeOrNot(n))
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}