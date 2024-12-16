#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution matrix
void printSolution(vector<vector<char>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at arr[row][col] is safe
bool isSafe(vector<vector<char>> &arr, int row, int col, int n)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (arr[row][i] == 'Q')
            return false;

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j] == 'Q')
            return false;

    // Check the lower diagonal on the left side
    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (arr[i][j] == 'Q')
            return false;

    return true;
}

// Recursive function to solve the N-Queen problem
bool solveNQueen(vector<vector<char>> &arr, int col, int n)
{
    // Base case: If all queens are placed, return true
    if (col >= n)
    {
        printSolution(arr, n);
        return true;
    }

    bool res = false;
    // Try placing the queen in all rows one by one
    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, i, col, n))
        {
            // Place the queen
            arr[i][col] = 'Q';

            // Recur to place rest of the queens
            res = solveNQueen(arr, col + 1, n) || res;

            // If placing queen in arr[i][col] doesn't lead to a solution
            // Backtrack and remove the queen
            arr[i][col] = '-';
        }
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    // Create an NxN chessboard initialized with '-'
    vector<vector<char>> arr(n, vector<char>(n, '-'));

    // Call the function to solve the N-Queen problem
    if (!solveNQueen(arr, 0, n))
    {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}
// solve using map