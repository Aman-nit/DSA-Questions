#include <iostream>
using namespace std;
int printCounting(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    // processing
    cout << n << endl;

    // recursive relation;
    printCounting(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    printCounting(n);
    return 0;
}
