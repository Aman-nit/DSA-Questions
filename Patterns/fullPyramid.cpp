#include <iostream>
using namespace std;

// Enter an integer:- 5
//          *
//        *  *
//      *  *  *
//    *  *  *  *
//  *  *  *  *  *

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
            cout << " * ";
        }

        cout << endl;
    }

    return 0;
}