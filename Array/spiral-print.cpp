#include <iostream>
#include <vector>
using namespace std;

void SpiralPrint(vector<vector<int>> arr, int n, int m)
{
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;
    int directio = 0;
    vector<int> ans;
    // 0(left-right ),1(top - bottom),2(right- left),3(bottom - top)

    while (colStart <= colEnd && rowStart <= rowEnd)
    {

        // left to right
        for (int i = rowStart; i < colEnd; i++)
        {
            ans.push_back(arr[rowStart][i]);
        }
        rowStart++;
        // top to bottom
        for (int j = colStart; j < rowEnd; j++)
        {
            ans.push_back(arr[j][colEnd]);
        }
        colEnd--;
        // right to left
        if (rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                ans.push_back(arr[rowEnd][i]);
            }
            rowEnd--;
        }
        // bottom to top
        if (colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                ans.push_back(arr[i][colStart]);
            }
            colStart++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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
    SpiralPrint(arr, n, m);

    return 0;
}