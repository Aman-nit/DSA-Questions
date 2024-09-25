#include <iostream>
#include <vector>
#include <math.h>

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

void setKthBit(vector<int> &ans, int k)
{

    if (ans[k + 1] == 0)
    {
        ans[k + 1] = 1;
    }
    else
    {
        ans[k + 1] = 1;
    }
}

int binaryToDecimal(vector<int> &ans)
{
    int decimalValue = 0;
    int length = ans.size();

    for (int i = 0; i < length; i++)
    {
        // Convert character '0' or '1' to int and multiply by the corresponding power of 2
        if (ans[length - 1 - i] == '1')
        {
            decimalValue += pow(2, i);
        }
    }

    return decimalValue;
}

int main()
{
    int n, k;
    vector<int> ans;
    cout << "Enter an integer:-";
    cin >> n;
    cout << "Enter the value of k:-";
    cin >> k;
    decimalToBinary(n, ans);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    setKthBit(ans, k);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << binaryToDecimal(ans);
    return 0;
}