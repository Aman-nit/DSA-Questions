#include <iostream>
#include <string.h>
using namespace std;

void tolowerCase(char string[])
{
    int n = strlen(string);
    for (int i = 0; i < n; i++)
    {
        if (string[i] != ' ')
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = string[i] - 'a' + 'A';
            }
        }
    }
    cout << string;
}

int main()
{
    char string[100];
    cout << "Enter a string:-";
    cin.getline(string, 100);
    tolowerCase(string);
}