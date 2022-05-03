#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

void bellmanFord(int n, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    bool negCycle = false;
    
    int x = -1;
    vector<int> relaxant(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {   x = -1; //resetting value of x every iteration
        negCycle = false;
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v]) //relaxation condition
            {
                negCycle = true;
                dist[v] = dist[u] + w;
                x = v; //marking the last edge node at the last nth iteration. Will be effective only in the last nth iteration, i.e.will execute only if neg cycle is found
                relaxant[v] = u; //storing relaxant node of each node in order to backtrack later
            }
        }
    }

    if (!negCycle)
        cout << "NO" << endl;
    else //if negative cycle is detected
    {
        cout << "YES" << endl;

        for (int i = 1; i < n; ++i) //backtracking (n-1) times in order to guarantee that we end up in the cycle for sure
        {
            x = relaxant[x];
        }
        vector<int> cycle;
        for (int v = x; ; v = relaxant[v]) //backtracking until we find the same node x again
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        for (auto el : cycle)
            cout << el << " ";
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }

    bellmanFord(n, edges);
}

int32_t main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}