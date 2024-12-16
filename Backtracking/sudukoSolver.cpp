// 4 5 0 0 0 0 0 0 0
// 0 0 2 0 7 0 6 3 0
// 0 0 0 0 0 0 0 2 8
// 0 0 0 9 5 0 0 0 0
// 0 8 6 0 0 0 2 0 0
// 0 2 0 6 0 0 7 5 0
// 0 0 0 0 0 0 4 7 6
// 0 7 0 0 4 5 0 0 0
// 0 0 8 0 0 9 0 0 0

#include <iostream>
#include <vector>

using namespace std;
bool isSafe(int value, vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (board[row][i] == value)
        {
            return false;
        }
        // col check
        if (board[i][col] == value)
        {
            return false;
        }
        // 3*3 box check
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
        {
            return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check cell is empty or not
            if (board[i][j] == 0)
            {
                // try to fill with values from 1 to 9
                for (int value = 1; value <= 9; value++)
                {
                    // check ,can we put that value in cell or not
                    if (isSafe(value, board, i, j))
                    {
                        // insertin value
                        board[i][j] = value;

                        // baki recursion sambhal lega
                        bool ageKaSolution = sudokuSolver(board, n);
                        if (ageKaSolution == true)
                        {
                            return true;
                        }
                        // backtracking
                        else
                        {
                            board[i][j] = 0;
                        }
                    }
                }
                // if 1-9 tuk koi v value se solution nhi nikla for current cell then pichla cell me  galti hai
                return false;
            }
        }
    }
    // all cell is filled
    return true;
}

int main()
{
    // o -> represent empty sell
    vector<vector<int>> board = {
        {4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 0, 6, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 8},
        {0, 0, 0, 9, 5, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 6, 0, 0, 7, 5, 0},
        {0, 0, 0, 0, 0, 0, 4, 7, 6},
        {0, 7, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 9, 0, 0, 0}};
    // vector<vector<int>> board(9, vector<int>(9, 0));
    // cout << "Enter the sudoku problem(empty sel = 0)";
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin >> board[i][j];
    //     }
    // }
    int n = 9;
    sudokuSolver(board, n);
    cout << "Printing solution......" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}