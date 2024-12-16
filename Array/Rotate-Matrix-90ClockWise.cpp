#include <iostream>
#include <vector>
// NORMAL MATTRIX
//  1 2 3
//  4 5 6
//  7 8 9
// ROTATED MATRIX 90 DEGREE CLOCK WISE
//  7 4 1
//  8 5 2
//  9 6 3
using namespace std;
int rotate90ClockWise(vector<vector<int>> arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    cout << "Enter number of rows:-";
    cin >> n;
    cout << "Enter number of coloums:-";
    cin >> m;
    cout << "Enter the values of " << "( " << n << " , " << m << " ) " << "matrix" << endl;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotate90ClockWise(arr, n, m);
    return 0;
}