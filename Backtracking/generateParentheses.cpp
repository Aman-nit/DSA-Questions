// we have given n opening bracket '(' and n ')' coled  barcket we have to find number of combination can be made from n brackets,
// ex (,),),),(,(; 3=>(,3=>),
// number of combination made =((())),()()(), ()(()),(()()),(())()
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void generateParentheses(vector<string> &ans, int open, int close, int n, string output, int &count)
{
    // Base case
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        count += 1;
        return;
    }
    // include open bracket
    if (open > 0)
    {
        output.push_back('(');
        generateParentheses(ans, open - 1, close, n, output, count);
        // backtracking
        output.pop_back();
    }

    // include close bracket
    if (close > open)
    {
        output.push_back(')');
        generateParentheses(ans, open, close - 1, n, output, count);
        // backtraking
        output.pop_back();
    }
}

int main()
{
    int n;
    cout << "Enter number of opening and closing bracket:-";
    cin >> n;
    int open = n;
    int close = n;
    string output = "";
    vector<string> ans;
    int count = 0;
    generateParentheses(ans, open, close, n, output, count);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        cout << endl;
    }
    cout << "Total number of combination is = " << count << " ";
    return 0;
}