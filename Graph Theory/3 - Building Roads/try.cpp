#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[v] = true;

    for (auto ad : adj[v])
    {
        if (!visited[ad])
        {
            dfs(ad, adj, visited);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>({}));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> heads;
    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            heads.push_back(i); // we are pushing starting node from each connected component into array, we will need to build edges between these nodes in order to make the whole graph connected
            dfs(i, adj, visited);
            cc++;
        }
    }

    cout << cc - 1 << endl; // since number of edges that need to be built in order to connect the whole graph will always be number of connected componentsm minus 1
    for (int i = 1; i < heads.size(); i++)
        cout << heads[i] << " " << heads[i - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}