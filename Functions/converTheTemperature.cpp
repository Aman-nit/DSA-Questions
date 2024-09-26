#include <iostream>
using namespace std;

void convertTheTemperature(float celsius)
{
    float kelvin = celsius + 273.15;
    float farenheit = 1.80 * celsius + 30.00;
    float ans[2];
    ans[0] = kelvin;
    ans[1] = farenheit;

    cout << "[ " << ans[0] << " , " << ans[1] << " ]" << endl;
}

int main()
{

    float celsius;
    cout << "Enter temperature in celsius:-" << endl;
    cin >> celsius;
    convertTheTemperature(celsius);

    return 0;
}