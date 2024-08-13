#include <iostream>
#include <string.h>
using namespace std;
string removeOccurance(string str, string part)
{
    int pos = str.find(part);
    while (pos != string::npos)
    {
        str.erase(pos, part.length());
        pos = str.find(part);
    }
    return str;
}

int main()
{
    char str[100];
    char part[100];
    cout << "Enter a string:-";
    cin.getline(str, 100);
    cout << "Enter a string to remove:-";
    cin.getline(part, 100);
    string ans = removeOccurance(str, part);
    cout << ans;

    return 0;
}