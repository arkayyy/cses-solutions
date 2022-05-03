#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//ALGO: Using Bipartite algo of graph to divide all the nodes into 2 different categories

bool dfs(int v, vector<vector<int>>& adj, vector<bool> & visited, vector<int>& color)
{
    visited[v] = true;

    int temp = true;

    for(auto ad: adj[v])
    {
        if(!visited[ad])
        {
            color[ad] = (color[v]^3);
            temp = temp && dfs(ad,adj,visited,color); //storing result of all adjacents dfs, it any adjacent dfs returns false, then result for current node dfs is also false
        }
        else
        {
            if(color[ad]==color[v]) //contradiction: if any adjacent node has already been visited but has the same color as the current node
                return false;
        }
    }
    return temp;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1,vector<int>({}));
    for(int i = 0; i<m ;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1,false);
    vector<int> color(n+1,1);

    bool ans = true;

    for(int i = 1;i<=n;i++)
    {
        if(!visited[i])
        {
            ans = (ans && dfs(i,adj,visited,color));
        }
    }

    if(!ans) {cout<<"IMPOSSIBLE"<<endl; return;}

    for(int i = 1; i<=n;i++)
    {
        cout<<color[i]<<" ";
    }

}

int main()
{
    ios;
    int t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}