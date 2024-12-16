#include <iostream>
#include <vector>
using namespace std;

void printDigit(int n)
{
    // Base casae
    if (n == 0)
    {
        return;
    }
    // RR
    printDigit(n / 10);
    // processing
    int digit = n % 10;
    cout << digit << endl;
}

int main()
{
    int n;
    cout << "Enter a integer:-";
    cin >> n;
    if (n == 0)
        cout << " 0";
    printDigit(n);

    return 0;
}