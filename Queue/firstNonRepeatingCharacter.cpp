#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main()
{

    string str = "";
    int freq[26] = {0};
    queue<char> q;
    string ans = "";
    cout << "Enter a string here:- ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // increment frequency of char
        freq[ch - 'a']++;

        q.push(ch);
        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    cout << "Your final answer is: ";
    cout << ans << " ";

    return 0;
}