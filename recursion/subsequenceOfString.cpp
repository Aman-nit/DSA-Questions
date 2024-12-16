#include <iostream>
#include <string>
using namespace std;

void subsetOfString(const string &str, string &output, int i)
{
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // Exclude the current character
    subsetOfString(str, output, i + 1);

    // Include the current character
    output.push_back(str[i]);
    subsetOfString(str, output, i + 1);

    // Backtrack: remove the current character
    output.pop_back();
}

int main()
{
    string str;
    string output = "";
    cout << "Enter a string: ";
    getline(cin, str);
    subsetOfString(str, output, 0);
    return 0;
}
