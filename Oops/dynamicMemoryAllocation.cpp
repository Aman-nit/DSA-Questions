#include <iostream>
using namespace std;

int main()
{
    int row = 5;
    int col = 5;
    int **arr = new int *[5];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // printing
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}