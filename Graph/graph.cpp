#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

// creating Adjacency list
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {

        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // creating an edge from u to v;
        adjList[u].push_back({v, weight});
        if (direction == 0)
        {
            // undirected edge
            // creating an edge from v to u
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjacency()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << ") ";
            }
            cout << endl;
        }
    }
};

// Creating graph using Adjacency Matrix
void adjacencyMatrix()
{
    int n, e;
    cout << "Enter number of nodes:- \n";
    cin >> n;
    cout << "Enter number of edges:-\n";
    cin >> e;
    vector<vector<int>> adj(n, (vector<int>(n, 0)));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        // for weighted graph place weight instead of 1
        adj[u][v] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Creating graph using Adjacency Matrix
    // adjacencyMatrix();

    // creating graph using Adjacency List
    // undirected edge
    // g.addEdge(srecNode,destnode,weight,direction)
    graph g;
    g.addEdge(0, 1, 0, 0);
    g.addEdge(1, 2, 0, 0);
    g.addEdge(0, 2, 0, 0);
    g.printAdjacency();
    cout << "\n\n";

    // Directed edge
    // g.addEdge(srecNode,destnode,weight,direction)
    graph gr;
    gr.addEdge(0, 1, 8, 1);
    gr.addEdge(1, 2, 5, 1);
    gr.addEdge(0, 2, 7, 1);
    gr.printAdjacency();

    return 0;
}