#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

//ALGO: Here we do bellman ford algo to find the SSSP with negated edge weights 
//(since single source largest path is equivalent to signel source shortest path with negated edges)

//Now, BF algo can only be performed with directed graphs;
//So, if we have a directed graph, we need to store a normal adjacent list and a backward adjacent list.
//Then we need to perform DFS on both these adjacent lists ( in normal adj list, we begin from 1 say, and in reversed adj list we begin from n)
//We will maintain 2 separated visited array for both DFS
//Then we will relax only those edges containing nodes which have been visited in both DFS, and satisfy the standard relaxation condition of cost.

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[v] = true;
    for(auto ad: adj[v])
    {
        if(!visited[ad])
            dfs(ad,adj,visited);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);

    vector<vector<int>> adj2(n+1);
    vector<bool> visited2(n+1,false);
    
    vector<vector<int>> edges;
    vector<int> dist(n+1,INF);
    dist[1] = 0;

    for(int i =0; i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,0-c});
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    dfs(1,adj,visited);
    dfs(n,adj2,visited2);

    //Now performing actual BF algo
    bool negCycle = false;
    for(int i = 1; i<=n; i++)
    { negCycle = false; //resetting to false, so that only if in the nth iteration if the relaxation condition still holds true, we know cycle is detected and thus negCycle will become true and the loop will end
       for(auto e: edges)
       {
           int u = e[0], v = e[1], w = e[2];
           if(visited[u] && visited2[v] && dist[u]+w < dist[v]) // IMPPPP: relaxation condition for BF algo for undirected graph (converted into 2 adjacent lists, one reverse of other)
           {
               negCycle = true; //this statement will get effective only for the last(nth iteration) which is for checking for negative cycle
               //fror all other iterations, it will be reset to false at the starting of the previous enclosing loop...
               dist[v] = dist[u] + w;
           }
       }
    }

    if(negCycle) cout<<-1<<endl;
    else
        cout<<0-dist[n]<<endl;

}

int32_t main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}