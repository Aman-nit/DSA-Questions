#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binarysearch(int arr[][4], int rows, int cols, int target)
{
}

int main()
{

    int arr[5][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int row = 5;
    int col = 4;
    int target;
    bool ans = binarysearch(arr, row, col, target);

    return 0;
}