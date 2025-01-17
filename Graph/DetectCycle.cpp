/*
  We've given an Graph we wanted to find whether
  it contains cycle or not
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool detectCycle(int src, vector<vector<int>> &adj, vector<int> &vis)
{ // Using BFS Algo
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1}); // -1 Signifies that it came from no where
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] == -1) // Not visited
            {
                vis[it] = 1;
                q.push({node, it}); // as it is discoverd by node so it is his parent
            }
            else if (parent != it)
            {
                return true; // It contains cycle as it is already visited
            }
        }
    }
    return false;
}
bool isCycle(int v, vector<vector<int>> &adj)
{
    vector<int> vis(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == -1)
        {
            if (detectCycle(i, adj, vis))
                return true;
        }
    }
    return false;
}
void addNode(int u, int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v); // For Directed Graph u->v
}

int main()
{  
    int v=5;
    vector<vector<int>>adj;
    addNode(1,2,adj);
    addNode(2,3,adj);
    addNode(3,4,adj);
    addNode(4,5,adj);
    addNode(5,2,adj);
    cout<<isCycle(v,adj);

    return 0;
}