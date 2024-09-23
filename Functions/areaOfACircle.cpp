#include <iostream>
using namespace std;
int AreaOfCircle(int r)
{
    float pi = 3.14;
    float area = pi * r * r;
    cout << "Area of Circle is " << area;
}
int main()
{
    int r;
    cout << "Enter the radius of circle:-";
    cin >> r;
    AreaOfCircle(r);

    return 0;
}