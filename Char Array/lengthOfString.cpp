#include <iostream>
#include <string.h>
using namespace std;
int getLength(char ch[])
{
    int length = 0;
    int i = 0;
    while (ch[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

int main()
{
    char ch[100];
    cout << "Enter your name:-";
    cin.getline(ch, 50);

    int size = getLength(ch);
    cout << "Length of your name is :-" << size << endl;
    cout << "Length of your name is :-" << strlen(ch);
    return 0;
}