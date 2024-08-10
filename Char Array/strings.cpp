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
        cout << "a and b are exactly same string" << endl;
    }
    else
    {
        cout << "a and b are not same " << endl;
    }
    string sentence = "hello my man how are you ";
    string target = "Aman";
    /*if (sentence.find(target) == std::string::npos)
    {
        cout << "Target found" << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }*/

    // replaced function
    sentence.replace(0, 5, target);
    cout << sentence;

    return 0;
}