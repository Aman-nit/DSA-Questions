#include <iostream>
#include <string.h>
using namespace std;

bool revreString(char string[])
{
    int n = strlen(string);
    int s = 0;
    int end = n - 1;
    while (s <= end)
    {
        if (string[s] == string[end])
        {
            s++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char string[100];
    cout << "Enter a string:-";
    cin.getline(string, 100);
    int value = revreString(string);
    if (value == 1)
    {
        cout << " it iS a palindrom string. " << endl;
    }
    else
    {
        cout << "it is not a palindrom string." << endl;
    }
    // main();
    return 0;
}