#include <iostream>
using namespace std;

int MaxOfThree(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else
        return c;
}

int main()
{
    int a, b, c;
    cout << "Enter The value of A:-";
    cin >> a;
    cout << "Enter The value of B:-";
    cin >> b;
    cout << "Enter The value of C:-";
    cin >> c;
    cout << MaxOfThree(a, b, c);
    return 0;
}