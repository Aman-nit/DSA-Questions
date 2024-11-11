#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// brute force
string longestCommonprefix(vector<string> &str)
{

    string ans = "";
    if (str.empty())
        return ans;
    // loop on first string
    for (int i = 0; i < str[0].length(); i++)
    {
        char ch = str[0][i];
        bool match = true;

        // compare this character with all
        // the remaining strings at the  same index
        for (int j = 0; j < str.size(); j++)
        {
            // compare
            if (str[j].size() <= i || ch != str[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

// Using tries

int main()
{
    int n;
    cout << "Enter the number of string :-";
    cin >> n;
    cin.ignore();
    vector<string> str(n, "");
    cout << "Please enter the strings.." << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }
    string ans = longestCommonprefix(str);
    cout << "longest commn prefix is ";
    cout << "'" << ans << "'" << endl;

    return 0;
}