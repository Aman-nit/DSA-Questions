#include <iostream>
using namespace std;
//  A
//  A B A
//  A B C B A
//  A B C D C B A
//  A B C D E D C B A
int main()
{
    int n;
    cout << "Enter a number:- ";
    cin >> n;
    // OUTER LOOP FOR ROW
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i + 1; j++)
        {
            int ans = j;
            char ch = 'A' + ans;
            cout << " " << ch;
        }
        j = j - 1;
        for (; j >= 1; j--)
        {
            int ans = j - 1;
            char ch = ans + 'A';
            cout << " " << ch;
        }

        cout << endl;
    }

    return 0;
}