#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int v, unordered_map<int,vector<int>>& adj, vector<int>& temp, vector<bool>&visited)
{
    if(visited[v]) return;
    
    visited[v] = true;

    for(auto ad: adj[v])
        dfs(ad, adj, temp, visited);

    temp.push_back(v);
}

void dfs2(int v, unordered_map<int,vector<int>>& adj2, int &k, vector<int>& comp, vector<bool>& visited)
{
    if(visited[v]) return;
    
    visited[v] = true;
    comp[v] = k; 
    for(auto ad: adj2[v])
        dfs2(ad, adj2, k, comp, visited);
}

void solve()
{
    ll n,m;
    cin>>n>>m;

    unordered_map<int, vector<int>> adj;
    unordered_map<int,vector<int>> adj2;

    vector<bool> visited(2*m + 1, false);

    vector<int> temp;

    vector<int> comp(2*m + 1 , 0);

    int k = 0;

    for(int i=0;i<n;i++)
    {
        char x, y;
        ll a, b;
        cin>>x>>a>>y>>b;
        if(x=='-') a = 2*m + 1 - a;
        if(y=='-') b = 2*m + 1 - b;
        adj[2*m + 1 - a].push_back(b); adj[2*m + 1 - b].push_back(a);
        adj2[b].push_back(2*m + 1 - a); adj2[a].push_back(2*m + 1 - b);
    }

    for(int i = 1; i<2*m+1; i++)
    {
        if(!visited[i])
            dfs(i,adj,temp, visited);
    }

    fill(visited.begin(), visited.end(), false);

    for(auto i = temp.rbegin(); i!=temp.rend() ; i++)
    {
        int t = *i;
        if(!visited[t])
        {
            k++;
            dfs2(t,adj2,k,comp,visited);
        }
    }
    vector<int> tval(m+1,false);

    for(int i=1; i<= m; i++)
    {
        if (comp[i]==comp[2*m-i+1]){cout<<"IMPOSSIBLE"<<endl; return;}
        tval[i] = (comp[i]>comp[2*m-i+1]);
    }
    for(int i=1; i<= m; i++){
        cout<<((tval[i])?'+':'-')<<" ";
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}