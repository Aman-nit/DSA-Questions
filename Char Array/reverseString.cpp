#include <iostream>
#include <string.h>
using namespace std;

void revreString(char ch[])
{
    int n = strlen(ch);
    int s = 0;
    int end = n - 1;
    while (s <= end)
    {
        swap(ch[s], ch[end]);
        s++;
        end--;
    }
    cout << "Reverse of your name :-";
    cout << ch;
}

int main()
{
    char ch[100];
    cout << "Enter your name:-";
    cin.getline(ch, 50);
    revreString(ch);

    return 0;
}