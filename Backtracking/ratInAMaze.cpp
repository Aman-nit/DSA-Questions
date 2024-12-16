#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

// Check if the cell (x, y) is within bounds, not blocked, and not visited
bool isSafe(int x, int y, int row, int col, vector<vector<int>> maze, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 1 && !visited[x][y]);
}

// Recursive function to solve the maze
void solveMaze(vector<vector<int>> maze, int row, int col, int i, int j, vector<string> &path, string &output, vector<vector<bool>> &visited)
{
    // Base case: If we have reached the destination cell
    if (i == row - 1 && j == col - 1)
    {
        path.push_back(output);
        return;
    }

    // Mark the cell as visited
    visited[i][j] = true;

    // Move Down
    if (isSafe(i + 1, j, row, col, maze, visited))
    {
        output.push_back('D');
        solveMaze(maze, row, col, i + 1, j, path, output, visited);
        output.pop_back(); // Backtrack
    }

    // Move Left
    if (isSafe(i, j - 1, row, col, maze, visited))
    {
        output.push_back('L');
        solveMaze(maze, row, col, i, j - 1, path, output, visited);
        output.pop_back(); // Backtrack
    }

    // Move Right
    if (isSafe(i, j + 1, row, col, maze, visited))
    {
        output.push_back('R');
        solveMaze(maze, row, col, i, j + 1, path, output, visited);
        output.pop_back(); // Backtrack
    }

    // Move Up
    if (isSafe(i - 1, j, row, col, maze, visited))
    {
        output.push_back('U');
        solveMaze(maze, row, col, i - 1, j, path, output, visited);
        output.pop_back(); // Backtrack
    }

    // Unmark the cell as visited for backtracking
    visited[i][j] = false;
}

int main()
{
    int row;
    int col;
    cout << "Enter nmumber of rows of maze:-";
    cin >> row;
    cout << "Enter number of col of maze:-";
    cin >> col;
    if (row != col)
    {
        cout << "Please enter the correct maze size.";
    }
    cout << "Enter the maze matrix.";
    vector<vector<int>> maze(row, (vector<int>(col)));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // Check if the starting or ending cell is blocked
    if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0)
    {
        cout << "No path possible" << endl;
        return 0;
    }

    vector<string> path;
    string output = "";
    visited[0][0] = true; // Mark the starting cell as visited
    solveMaze(maze, row, col, 0, 0, path, output, visited);

    // Sort paths in lexicographical order
    sort(path.begin(), path.end());

    // Print the paths
    cout << "Printing the results paths: " << endl;
    for (const auto &p : path)
    {
        cout << p << " ";
    }
    cout << endl;

    if (path.empty())
    {
        cout << "No path exists" << endl;
    }

    return 0;
}
