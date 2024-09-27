#include <iostream>
using namespace std;

// Enter an integer:- 5
//   * * * * *
//    * * * *
//     * * *
//      * *
//       *

int main()
{
    int n;
    cout << "Enter an integer:- ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        // Inverted Full Pyramid
        for (int k = 0; k < n - i; k++)
        {
            cout << " *";
        }
        cout << endl;
    }

    return 0;
}