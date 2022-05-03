#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define INF 1e18

//ALGO: For Round Trip problem I or II, we use DFS.

bool dfs(int v, vector<int> &cycle, vector<bool> &flag, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[v] = true;
   
    cycle.push_back(v);
    flag[v] = true;

    for (auto ad : adj[v])
    {
        if (!visited[ad])
        {
            if (dfs(ad, cycle, flag, adj, visited))
            {
                return true;
            }
        }
        if (flag[ad])
        {
            cycle.push_back(ad);
            return true;
        }
    }
    cycle.pop_back();
    flag[v] = false;

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> flag(n + 1, false); //we use this array to check if a node that is reached using DFS has already been included in the recursion stack
    //If it's already visited, it means cycle exists
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> cycle;

    bool cycleExists = false;

    for (int i = 1; i <= n; i++)
    {

        if (!visited[i])
        {
            
            if (dfs(i, cycle, flag, adj, visited))
            {
                //from the last we traverse backwards until we reach the last element. Since that last element is the node at which the cycle starts
                cycleExists = true;
                int start = *cycle.rbegin();
                vector<int> ans;
                for (auto it = cycle.rbegin(); it != cycle.rend(); it++)
                {
                    ans.push_back(*it);
                    if (start == *it && ans.size() > 1)
                        break;
                }
                reverse(ans.begin(),ans.end());
                cout<<ans.size()<<endl;
                for (auto a : ans)
                    cout << a << " ";
                return;
            }
            
        }
    }

    cout<<"IMPOSSIBLE"<<endl;

}

int32_t main()
{
    ios;
    int t = 1;
    while (t--)
        solve();
    return 0;
}