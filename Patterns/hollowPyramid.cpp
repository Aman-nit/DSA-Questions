#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // SPACE  INVERTED HALF PYRAMID
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // FULL PYRAMID

        for (int k = 0; k < i + 1; k++)
        {
            if (k == 0 || k == i || i == n - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}