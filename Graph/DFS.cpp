#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[src])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{
    graph g;
    int n = 7;
    // n -> number of nodes in graph

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    // g.addEdge(3, 7, 0);
    // g.addEdge(7, 6, 0);
    // g.addEdge(7, 4, 0);

    g.printAdjacencyList();

    cout << "Printing DFS \n ";
    // for Disconnected graph
    unordered_map<int, bool>
        visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited);
        }
    }

    return 0;
}