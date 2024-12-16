#include <iostream>
#include <vector>
using namespace std;

int maxiMini(int arr[][3], int row, int col)
{
    int min = INT16_MIN;
    int max = INT16_MAX;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > min)
            {
                min = arr[i][j];
            }
            if (arr[i][j] < max)
            {
                max = arr[i][j];
            }
        }
    }
    cout << max << endl;
    cout << min;
}

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
    maxiMini(arr, 3, 3);

    return 0;
}
