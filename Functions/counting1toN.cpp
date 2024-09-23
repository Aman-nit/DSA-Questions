#include <iostream>
using namespace std;
void counting(int a)
{
    for (int i = 0; i <= a; i++)
    {
        cout << i << endl;
    }
}
int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    counting(n);
    return 0;
}