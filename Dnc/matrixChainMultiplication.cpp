#include <iostream>
#include <climits>
using namespace std;

#define N 100

// Function to compute the minimum cost of matrix chain multiplication
int matrixChainOrder(int p[], int n)
{
    // m[i][j] stores the minimum number of multiplications needed for A[i]...A[j]
    int m[N][N];

    // No cost is needed for single matrix, so set all m[i][i] = 0
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            // Calculate cost of each possible split (k) between i and j
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    // The result is stored in m[1][n-1]
    return m[1][n - 1];
}

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[N];
    cout << "Enter the dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    cout << "Minimum number of multiplications is " << matrixChainOrder(p, n + 1) << endl;

    return 0;
}
