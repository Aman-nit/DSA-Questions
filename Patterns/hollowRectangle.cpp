#include <iostream>
using namespace std;

// Enter length of rectangle:-5 7
// Enter width of rectangle:-
//  * * * * * * *
//  *           *
//  *           *
//  *           *
//  * * * * * * *

int main()
{
    int n, m;
    cout << "Enter length of rectangle:-";
    cin >> n;
    cout << "Enter width of rectangle:-" << endl;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0) || ((i == n - 1) || (j == m - 1)))
            {
                cout << " *";
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