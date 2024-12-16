#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100
#define INF 99999 // A large number to represent infinity

// Function to print the solution matrix
void printSolution(int dist[MAX][MAX], int n)
{
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << setw(7) << "INF";
            }
            else
            {
                cout << setw(7) << dist[i][j];
            }
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(int graph[MAX][MAX], int n)
{
    int dist[MAX][MAX];

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, n);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    // Input number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Input the adjacency matrix
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph, n);

    return 0;
}
