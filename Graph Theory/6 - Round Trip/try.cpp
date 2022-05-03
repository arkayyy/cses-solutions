#include <bits/stdc++.h>
using namespace std;
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ret return

bool dfs(int v, int parent, vector<int> &seq, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[v] = true;
    bool temp = false;
    for (auto ad : adj[v])
    {
        seq.push_back(ad);
        if (!visited[ad])
        {
            if (dfs(ad, v, seq, adj, visited))
                return true;
        }
        // Intuition: If an adjacent node to current node is already visited, and the adjacent node is not current node's parent
        // that signifies that there is a cycle in the graph
        else if (parent != ad)
        {
            return true;
        }

        seq.pop_back();
    }

    return temp;
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
        adj[a].push_back(b); // Any road based problem means we have to take an undirected graph
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);

    vector<int> seq;

    for (int i = 1; i <= n; i++)
    {
        seq.push_back(i); //adding the current node in the seq
        if (!visited[i])
        {
            if (dfs(i, -1, seq, adj, visited)) // if loop is successfully found
            {
                //so since we have found the loop, we need to eliminate all the elements that were pushed to the seq before starting of the loop
                //so we are moving from end of the seq array (starting element of the loop) backwards , and moving till we find this element again in seq
                vector<int> ans;
                int val = *seq.rbegin(); 

                for (auto s = seq.rbegin(); s != seq.rend(); s++)
                {
                    ans.push_back(*s);
                    if (s!=seq.rbegin() && *s == val)
                        break;
                }
                cout << ans.size() << endl; //priting size of cycle
                reverse(ans.begin(),ans.end()); //reversing since we had added elements from seq to ans while moving backwards in seq
                for (auto a : ans)
                    cout << a << " ";
                return;
            }
        }
        seq.pop_back(); //popping the node from seq if it either has been visited, or if no cycle is found
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

int main()
{
    ios;
    int t = 1;
    while (t--)
    {
        solve();
    }
    ret 0;
}