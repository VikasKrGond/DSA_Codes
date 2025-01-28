/*
   Given Graph you have to color it in such a
   way that no two adjacent color are same
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
   the logic is simple we start with the first node and color
   it then we do the BFS and color them such that opposite to the
   neighbouring color and if they are already colored check wheter
   the neighbour have opposite color or not and if not then it's
   not a bipertite
   Note : if the graph is having the odd cycle then 
   it can't be a bipertite
*/
bool check(int start, int v, vector<vector<int>>adj, vector<int> col)
{
    queue<int> q;
    q.push(start);
    col[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int it : adj[node])
        {
            if (col[it] == -1)
            {
                col[it] = !col[node];
                q.push(it);
            }
            else if (col[it] == col[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipertite(int v, vector<vector<int>>adj)
{
    vector<int> col(v, -1); // Intially all vertices are not colored
    for (int i = 0; i < v; i++)
    {
        if (col[i] == -1)
        {
            if (check(i, v, adj, col) == false)
            {
                return false;
            }
        }
    }
    return false;
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}
int main()
{
    int v;
    cin >> v;
    vector<vector<int>>adj;
    for (int i = 0; i < v; i++)
    {
        int u, v;
        cout<<"Enter u and v : ";
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    if(isBipertite(v,adj))
    {
        cout<<"The Given Graph is Bipertite\n";
    }
    else{
        cout<<"The Given Graph is not Bipertite\n";
    }
    return 0;
}