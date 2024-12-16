#include <stdio.h>
#include <limits.h>

#define MAX 10 // Maximum number of cities

// Function prototypes
void swap(int *x, int *y);
void permute(int *array, int start, int end, int graph[MAX][MAX], int n, int *min_path, int *best_route);
int calculateCost(int *route, int graph[MAX][MAX], int n);
void printRoute(int *route, int n);

int main()
{
    int n;
    int graph[MAX][MAX];
    int route[MAX];
    int best_route[MAX];
    int min_path = INT_MAX;

    // Input number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Distance from city %d to city %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize route array
    for (int i = 0; i < n; i++)
    {
        route[i] = i;
    }

    // Generate all permutations and find the minimum path
    permute(route, 0, n - 1, graph, n, &min_path, best_route);

    // Print the best route and its cost
    printf("The shortest path is: ");
    printRoute(best_route, n);
    printf("Minimum cost: %d\n", min_path);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *array, int start, int end, int graph[MAX][MAX], int n, int *min_path, int *best_route)
{
    if (start == end)
    {
        int cost = calculateCost(array, graph, n);
        if (cost < *min_path)
        {
            *min_path = cost;
            for (int i = 0; i < n; i++)
            {
                best_route[i] = array[i];
            }
        }
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap((array + start), (array + i));
            permute(array, start + 1, end, graph, n, min_path, best_route);
            swap((array + start), (array + i)); // backtrack
        }
    }
}

int calculateCost(int *route, int graph[MAX][MAX], int n)
{
    int cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cost += graph[route[i]][route[i + 1]];
    }
    cost += graph[route[n - 1]][route[0]]; // Return to starting city
    return cost;
}

void printRoute(int *route, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", route[i]);
    }
    printf("%d\n", route[0]); // Return to starting city
}
