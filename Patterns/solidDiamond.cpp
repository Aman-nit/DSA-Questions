#include <iostream>
using namespace std;

// Enter a number:-9
//         *
//        * *
//       * * *
//      * * * *
//     * * * * *
//    * * * * * *
//   * * * * * * *
//  * * * * * * * *
// * * * * * * * * *
//  * * * * * * * *
//   * * * * * * *
//    * * * * * *
//     * * * * *
//      * * * *
//       * * *
//        * *
//         *

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;

    // UPPER HALF
    for (int i = 0; i < n; i++)
    {
        // INVERTED HALF PYRAMID
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // FULL PYRAMID
        for (int k = 0; k < i + 1; k++)
        {

            cout << "* ";
        }
        cout << endl;
    }

    // LOWER HALF
    for (int i = n - 2; i >= 0; i--)
    {
        // HALF PYRAMID
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}