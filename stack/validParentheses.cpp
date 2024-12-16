#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool validParentheses(stack<char> &s, string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char topch = s.top();
                if (ch == ')' && topch == '(')
                {
                    s.pop();
                }
                else if (ch == '}' && topch == '{')
                {
                    s.pop();
                }
                else if (ch == ']' && topch == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    stack<char> s;
    string str = "([)";

    if (validParentheses(s, str))
    {
        cout << "It is a valid parentheses ...." << endl;
    }
    else
    {
        cout << "It is not a valid parentheses." << endl;
    }

    return 0;
}