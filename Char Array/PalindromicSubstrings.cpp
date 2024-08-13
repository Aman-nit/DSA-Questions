// number of substring that is palindrom
// substring should be continues
// abc is a string, so substrings  are a,ab,abc,bc,b,c
#include <iostream>
#include <strings.h>
using namespace std;
int expandAroundIndex(string str, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < str.length() && str[i] == str[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstring(string str)
{
    int count = 0;
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        // odd
        int oddKaAns = expandAroundIndex(str, i, i);
        count += oddKaAns;
        // even
        int evevnKaAns = expandAroundIndex(str, i, i + 1);
        count += evevnKaAns;
    }
    return count;
}
int main()
{
    string str;
    cout << "Enter a string:-";
    getline(cin, str);
    int ans = countSubstring(str);
    cout << ans;

    return 0;
}