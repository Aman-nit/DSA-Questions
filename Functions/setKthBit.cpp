#include <iostream>
#include <vector>

using namespace std;

void decimalToBinary(int n, vector<int> &ans)
{

    while (n > 0)
    {
        int digit = n % 2;
        ans.push_back(digit);
        n /= 2;
    }
}

int main()
{
    int n;
    vector<int> ans;
    cout << "Enter an integer:-";
    cin >> n;
    decimalToBinary(n, ans);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}