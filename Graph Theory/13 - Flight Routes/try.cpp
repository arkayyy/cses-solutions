#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
#define int long long
#define INF 1e18

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b}); // {cost to adj node ,adjacent node}
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n + 1, vector<int>(k+1, LLONG_MAX)); //IMPPP: this is modified version of Djikstra, where in dist array we have a vector of vectors for every node.
    //it stores k shortest distances

    pq.push({0, 1});

    while (!pq.empty())
    {
        vector<int> temp = pq.top();
        pq.pop();

        if (dist[temp[1]][k] < temp[0]) //if the distance of the current popped node is already updated, we skip it
            continue;

        for (auto ad : adj[temp[1]])
        {
            if (temp[0] + ad[0] < dist[ad[1]][k]) //relaxation condition
            {
                dist[ad[1]][k] = temp[0] + ad[0];
                pq.push({dist[ad[1]][k], ad[1]});
                sort(dist[ad[1]].begin(), dist[ad[1]].end());
            }
        }
    }

    for (auto d = 0; d < k; d++)
        cout << dist[n][d] << " ";
}

int32_t main()
{
    ios;
    int t = 1;
    while (t--)
        solve();

    return 0;
}