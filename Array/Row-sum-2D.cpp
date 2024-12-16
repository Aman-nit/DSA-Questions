#include <iostream>
#include <vector>
using namespace std;

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
    cout << "Row wise sum:-" << endl;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum;
        cout << endl;
    }

    return 0;
}