#include <iostream>
using namespace std;

void sumOfNEvenNumber(int n)
{
    int ans = 0;
    for (int i = 0; i <= n; i += 2)
    {
        ans += i;
    }
    cout << "Sum of even numbers is " << ans << endl;
}

int main()
{
    int n;
    cout << "Enter value of n:- ";
    cin >> n;
    sumOfNEvenNumber(n);
    return 0;
}