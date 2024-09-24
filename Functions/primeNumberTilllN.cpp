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

void PrimeTillN(int n)
{
    if (n <= 1)
    {
        cout << "Please enter only +ve numbers." << endl;
        return;
    }

    for (int i = 2; i < n; i++)
    {
        if (isPrimeOrNot(i))
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    PrimeTillN(n);
    return 0;
}