#include <iostream>
using namespace std;

int AddNumber(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;
    cout << "Enter The value of A:-";
    cin >> a;
    cout << "Enter The value of B:-";
    cin >> b;
    cout << AddNumber(a, b);
    return 0;
}