
#include <iostream>
#include <string.h>
using namespace std;

void replaceSpace(char ch[])
{
    int n = strlen(ch);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (ch[s] == ' ')
        {
            ch[i] = '@';
        }
        s++;
    }

    cout << "printing sentence without any space:-" << endl;
    ;
    cout << ch;
}

int main()
{
    char ch[100];
    cout << "Enter your name:-";
    cin.getline(ch, 100);
    replaceSpace(ch);

    return 0;
}
