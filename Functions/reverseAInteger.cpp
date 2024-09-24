#include <iostream>
using namespace std;

int reverseInteger(int n)
{
    int reversedNumber = 0;
    while (n != 0)
    {
        int lastDigit = n % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        n = n / 10;
    }
    return reversedNumber;
}

int main()
{
    int n;
    cout << "Enter a number ";
    cin >> n;
    int reversedNumber = reverseInteger(n);
    cout << "Reversed number of " << n << " is " << reversedNumber;

    return 0;
}