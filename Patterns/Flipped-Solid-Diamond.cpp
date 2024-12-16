#include <iostream>
using namespace std;
// * * * * *   * * * * *
// * * * *       * * * *
// * * *           * * *
// * *               * *
// *                   *
// *                   *
// * *               * *
// * * *           * * *
// * * * *       * * * *
// * * * * *   * * * * *

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    // OUTER LOOP FOR ROWS
    for (int i = 0; i < n; i++)
    {
        // INVERTED HALF PYRAMID STARS
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        // SPACED FULL PYRAMID
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "  ";
        }
        // INVERTED HALF PYRAMID STARS
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    // LOWER HALF
    for (int i = 0; i < n; i++)
    {
        // HALF PYRAMID
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        // INVERTED FULL SPACED PYRAMID
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << "  ";
        }
        // HALF PYRAMID
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}