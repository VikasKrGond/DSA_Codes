
vector<int> topo(int v,vector<vector<int>>&adj)
{
    vector<int>indgree(V,0);
    for(int i=0;i<V;i++)
    {
         for(auto &it:adj[i])
         {
            indegree[it]++;  // calculating the indegree
         }
    }
   // to store the nodes with indegree 0
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vetor<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(int it:adj[node])  //Decreasing the indegree of the node 
        {
            indegree[it]--;
        }
        if(indegree[it]==0) q.push(it);
    }
}