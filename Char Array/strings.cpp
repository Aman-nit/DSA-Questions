#include <iostream>
#include <string>
// #include <string.h>
using namespace std;

int main()
{

    string str;
    cout << "Enter a string:-";
    getline(cin, str);
    // str[1] = '\0';
    cout << str;
    cout << "length:-" << str.length() << endl;
    cout << "is empty:-" << str.empty() << endl;
    cout << str.substr(0, 3) << endl;
    string a = "hello";
    string b = "hello";
    if (a.compare(b) == 0)
    {
        cout << "a and b are exactly same string";
    }
    else
    {
        cout << "a and b are not same " << endl;
    }
}