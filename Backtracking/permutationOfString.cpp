// BACKTRACKING
#include <iostream>
#include <string.h>
using namespace std;
void permutationOfString(string str, int i)
{
    if (i >= str.length())
    {
        cout << str << endl
             << " ";
        return;
    }
    // swapping
    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);
        // recall
        permutationOfString(str, i + 1);
        // backtracking - why>
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    int i = 0;
    // getline(cin, str);
    permutationOfString(str, i);
    return 0;
}