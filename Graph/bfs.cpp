#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// We define graph as matrix 
// For BFS we use Queue to Store the Vertex and 
// Visited array to keep track of all visited vertex
// We've given the Source and we've to print the bfs
void bfs(vector<vector<int>>&graph,int source)
{
    int n=graph.size();
    vector<bool>vis(n,false);
    queue<int>q;
    vis[source]=true; // Marking the source as visited
    q.push(source);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        cout<<a<<" ";
        for(int &i:graph[a])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=true;
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj,
                          int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}

int main() 
{
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);

    return 0;
}