#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    // char name[100];
    // cout << "Enter your name:-";
    // cin >> name;
    // cout << "Your name is " << name << endl;
    //  char crr[100];
    //  char crr[0] = "a";
    //  char crr[1] = 'b';
    //  char crr[2];
    // for (int i = 0; i < 5; i++)
    // {
    //    cout << "index : " << i << " value : " << name[i] //<< endl;
    // }
    // cout << (int)name[4] << " ";

    // cin function is unable to detect char after a space ,tab ,and enter
    char arr[100];
    // cin >> arr;

    cin.getline(arr, 50);
    cout << arr;

    return 0;
}
