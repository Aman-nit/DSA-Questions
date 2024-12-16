#include <iostream>
#include <stack>
#include <string>

// We are given a string consisting of '(' and ')' characters, representing opening and closing parentheses. The goal is to find the length of the longest substring of valid parentheses, where valid parentheses mean each opening '(' has a matching closing ')' in the correct order

using namespace std;

int longestValidParentheses(string str)
{
    stack<int> st;
    st.push(-1);    // Initialize stack with -1 to handle the base case of the first valid substring
    int maxLen = 0; // To store the maximum length of valid parentheses found

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i]; // Get the current character in the string
        if (ch == '(')
        {
            // If an opening parenthesis, push its index onto the stack
            st.push(i);
        }
        else
        {
            // If a closing parenthesis, pop from the stack
            st.pop();
            if (st.empty())
            {
                // If stack becomes empty, push the current index to mark a new base for future valid substrings
                st.push(i);
            }
            else
            {
                // If stack is not empty, calculate the length of the current valid substring
                int len = i - st.top();
                maxLen = max(len, maxLen); // Update maxLen if the current length is greater
            }
        }
    }
    return maxLen; // Return the maximum length of valid parentheses found
}

int main()
{
    string str; // Input string containing parentheses
    cout << "Please enter only ( ) these bracket combinations:-" << endl;
    getline(cin, str);
    cout << "Longest valid parentheses length: " << longestValidParentheses(str) << endl;
    return 0;
}
