#include <iostream>
#include <vector>
using namespace std;
// 1 2 3
// 4 5 6
// 7 8 9
// Wave print of above matrix
// 1 4 7 8 5 2 3 6 9

void WavePrintMatrix(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int k = n - 1; k >= 0; k--)
            {
                cout << arr[k][i] << " ";
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter number of rows:-";
    cin >> n;
    cout << "Enter number of coloums:-";
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    WavePrintMatrix(arr);
    return 0;
}