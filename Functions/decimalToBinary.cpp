#include <iostream>
#include <vector>
using namespace std;

void decimalToBinary(int n, vector<int> &v)
{

    while (n > 0)
    {
        int ans = n % 2;
        v.push_back(ans);
        n = n / 2;
    }
}

int main()
{

    int n;
    vector<int> v;
    cout << "Enter a decimal number:-";
    cin >> n;

    decimalToBinary(n, v);
    cout << "Binary number of " << n << " is ." << endl;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }

    return 0;
}
