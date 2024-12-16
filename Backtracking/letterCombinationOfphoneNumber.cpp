// Given a string containing digits from 2 to 9, create all possible letter combinations that the digits could represent on a telephone keypad. Return the combinations in any order.
// Each digit maps to a set of letters as follows:
//    2-"abc,
//    3-"def"
//    4-"ghi"
//    5-"jkl"
//    6-"mno"
//    7-"pqrs"
//    8-"tuv"
//    9-"wxyz"

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void letterCombinationOfNumber(vector<string> &ans, int index, string output, string digit, vector<string> mapping)
{
    // base case
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    // 1 case solve krna hai baki recursion sambhal lega
    int digits = digit[index] - '0';
    string value = mapping[digits];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        letterCombinationOfNumber(ans, index + 1, output, digit, mapping);
        // Backtracking
        output.pop_back();
    }
}

int main()
{
    int index = 0;
    string digit;
    cout << "Enter adigit:-";
    getline(cin, digit);
    vector<string> ans;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    if (digit.length() == 0)
    {
        return 0;
    }

    letterCombinationOfNumber(ans, index, output, digit, mapping);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i];
    //     cout << endl;
    // }

    for (const string &s : ans)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}