#include <iostream>
using namespace std;

int celciusToFaranheit(int &c)
{
    int f = (c * 9 / 5) + 32;
    return f;
}

int main()
{

    int c;
    cout << "Enter temperature in celcius:-";
    cin >> c;
    int f = celciusToFaranheit(c);
    cout << c << "degree celsius in Farenheit is : " << f;
}