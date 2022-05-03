#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &adj, vector<int> &par)
{
    int level = 0;
    int n = adj.size() - 1;

    queue<int> q;
    q.push(1);

    vector<bool> visited(adj.size(), false);
    visited[1] = true;

    while (!q.empty())
    {
        int len = q.size();
        level++;

        while (len--)
        {
            int t = q.front();
            q.pop();
            if (t == n)
                return level;
            for (auto ad : adj[t])
            {
                if (!visited[ad])
                {
                    visited[ad] = true;
                    par[ad] = t;
                    q.push(ad);
                }
            }
        }
    }

    return -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>({}));
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int noMessages = bfs(adj, parent);

    if (noMessages == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << noMessages << endl;

    int currNode = n;

    vector<int> route(noMessages);
    int lenRoute = noMessages;

    while (currNode != -1)
    {
        route[--lenRoute] = currNode;
        currNode = parent[currNode];
    }
    for (auto r : route)
        cout << r << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}