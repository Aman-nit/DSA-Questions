#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[3][3];
    cout << "Enter the values of 3*3 matrix:-" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int l = 0; l < 3; l++)
        {
            cout << arr[i][l] << " ";
        }
        cout << endl;
    }

    return 0;
}