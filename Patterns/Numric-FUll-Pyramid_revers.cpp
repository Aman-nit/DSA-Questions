#include <iostream>
using namespace std;

//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

int main()
{
    int n;
    cout << "Enter a number:- ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // SPACE
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        // HALF COUNTING
        int start = i + 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << start;
            cout << " ";
            start++;
        }
        // RIGHT HALF
        start = i * 2;
        for (int j = 0; j < i; j++)
        {
            cout << start << " ";
            start--;
        }

        cout << endl;
    }

    return 0;
}
