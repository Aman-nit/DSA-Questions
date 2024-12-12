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

    void bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            cout << frontnode << ", ";

            // Inserting neighbours
            for (auto neighbour : adjList[frontnode])
            {

                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
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
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);

    g.printAdjacencyList();

    cout << "Printing BFS\n";
    // for Disconnected graph
    unordered_map<int, bool> visited;
    for (int i = 0; i <= 8; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    return 0;
}