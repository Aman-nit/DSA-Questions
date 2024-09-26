#include <iostream>
#include <vector>
using namespace std;

void convertTheTemperature(float celsius)
{
    float kelvin = celsius + 273.15;
    float farenheit = 1.80 * celsius + 30.00;
    vector<float> ans;
    ans.push_back(kelvin);
    ans.push_back(farenheit);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }
}

int main()
{

    float celsius;
    cout << "Enter temperature in celsius:-" << endl;
    cin >> celsius;
    convertTheTemperature(celsius);

    return 0;
}