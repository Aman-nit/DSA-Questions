#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrom(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] == str[j])
        {
            return true;
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
}

bool conertToPalindrom(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
        {
            int a = checkPalindrom(str, i + 1, j);
            int b = checkPalindrom(str, i, j - 1);
            return a || b;
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;
}

int main()
{
    char str[100];
    cout << "Enter a string:-";
    cin.getline(str, 100);
    bool ans = conertToPalindrom(str);
    if (ans == 1)
    {
        cout << str << "  can be converted to a palindrom.";
    }
    else
    {
        cout << str << " cant be converted to a palindrom.";
    }

    return 0;
}