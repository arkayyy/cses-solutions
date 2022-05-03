#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> &curr, vector<int> &ans, vector<vector<int>> &adj, int source, vector<bool> &visited)
{
   // cout<<curr.size()<<endl;
    if (v == source && curr.size() > 1)
    {
        ans.clear();
        for(auto el: curr)
            ans.push_back(el);
        ans.push_back(source);
        return;
    }

    for (auto ad : adj[v])
    {
        if(ad==source)
            dfs(ad, curr, ans, adj, source, visited);
        else if (!visited[ad])
        {
            //cout<<"HI"<<endl;
            visited[ad] = true;
            curr.push_back(ad);
            dfs(ad, curr, ans, adj, source, visited);
            visited[ad] = false;
            curr.pop_back();
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>({}));
    vector<bool> visited(n + 1, false);
    vector<int> curr;
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = true;
        curr.push_back(i);
        dfs(i, curr, ans, adj, i, visited);
        curr.pop_back();
        visited[i] = false;
    }

    for (auto a : ans)
        cout << a << " ";

    return 0;
}