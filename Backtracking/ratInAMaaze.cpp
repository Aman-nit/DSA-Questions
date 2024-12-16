#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> maze, int i, int j, int n)
{
}

void ratInAmaze(vector<vector<int>> maze, int i, int j, int n)
{
    // base case
    if (maze[i][j] == maze[n][n])
    {
        return;
    }
    // 1 case solve krna hai
    if (isSafe(maze, i, j, n))
    {
    }
}

int main()
{

    int n;
    int i = 0;
    int j = 0;
    cout << "Enter a N*N matrix maze:-";
    cin >> n;
    vector<vector<int>> maze(n, (vector<int>(n)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInAmaze(maze, i, j, n);
}