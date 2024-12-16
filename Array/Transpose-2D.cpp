#include <iostream>
#include <vector>
using namespace std;
int Transpose(vector<vector<int>> arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i <= j)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    cout << "Printing transpose of an mattrix:-" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    int n;
    int m;
    cout << "Enter number of rows:-";
    cin >> n;
    cout << "Enter number of col:-";
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout
        << "Enter the values of " << "( " << n << " , " << m << " )" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    Transpose(arr, n, m);
    return 0;
}
