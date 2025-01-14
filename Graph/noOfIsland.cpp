#include<iostream>
#include<vector>
//We've given water as 0 and land as 1 the island is surrounded 
// by water i.e 0 so we'll run as dfs and mark all 1's as
// 2 so that these will count as one island

void markIsland(vector<vector<int>>&grid,int x,int y,int r,int c)
{
    if(x<0 || y<0 || x>r || y>c || grid[x][y]!=1) return;
    grid[x][y]=2;
    markIsland(grid,x,y+1,r,c);
    markIsland(grid,x+1,y,r,c);
    markIsland(grid,x,y-1,r,c);
    markIsland(grid,x-1,y,r,c);
}

int numOfIsland(vector<vector<int>&grid)
{
    int r=grid.size();
    if(r==0) return 0;
    int c=grid[0].size();
    int island=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]==1)
            {
                markIsland(grid,i,j,r,c);
                island++;
            }
        }
    }
    return island;
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
 
}