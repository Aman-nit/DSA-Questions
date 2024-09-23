#include <iostream>
using namespace std;

bool isEvenOrOdd(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout << "Enter a Number:-";
    cin >> n;
    bool ans = isEvenOrOdd(n);
    if (ans == true)
    {
        cout << n << " is a even number.";
    }
    else
    {
        cout << n << " is a odd number.";
    }
    return 0;
}