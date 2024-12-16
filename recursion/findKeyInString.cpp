#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void checkKey(string &str, char &key, int i, vector<int> &answer)
{
    // Base case
    if (i >= str.length())
    {
        return;
    }

    // operation
    if (str[i] == key)
    {
        answer.push_back(i);
        // cout << "found at " << i << endl;
    }
    // RR
    checkKey(str, key, i + 1, answer);
}

int main()
{
    string str;
    char key;
    vector<int> answer;
    cout << "Enter a string:-";
    getline(cin, str);
    cout << "Enter a character to find:-";
    cin >> key;
    int i = 0;
    checkKey(str, key, i, answer);
    for (auto val : answer)
    {
        cout << key << " is found at index:- " << val << endl;
    }
    return 0;
}