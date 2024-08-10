#include <iostream>
#include <string.h>
using namespace std;

void toLowerCase(char string[])
{
    int n = strlen(string);
    for (int i = 0; i < n; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] - 'A' + 'a';
        }
    }
    cout << string;
}

int main()
{
    char string[100];
    cout << "Enter a string:-";
    cin.getline(string, 100);
    toLowerCase(string);
}