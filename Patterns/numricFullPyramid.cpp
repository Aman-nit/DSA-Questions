#include <iostream>
using namespace std;

// Enter an integer:- 5
//          1
//        1  2
//      1  2  3
//    1  2  3  4
//  1  2  3  4  5

int main()
{

    int n;
    cout << "Enter an integer:- ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "  ";
        }
        // stars
        for (int k = 0; k < i + 1; k++)
        {
            cout << " " << k + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}