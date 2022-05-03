#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define INF 1e18
#define pb push_back
#define vi vector<int>
#define qi queue<int>

//ALGO: Standard Topological Sorting
void topo(int n, vector<vector<int>> adj, vector<int> inDegree)
{
    vi ans;
    qi zeroInDegree;
    for(int i = 1;i<=n;i++) //initially pushing all nodes with indegree=0
        if(!inDegree[i])
            zeroInDegree.push(i);
    
    while(!zeroInDegree.empty()) //we are then popping one node at a time from queue and decreasing indegree of all its adjacents by 1 and check if any of their indegree=0 and pushing that into queue
    {
        int t = zeroInDegree.front();
        ans.pb(t);
        zeroInDegree.pop();
        for(auto ad: adj[t])
        {
            --inDegree[ad];
            if(!inDegree[ad])
                zeroInDegree.push(ad);
        }
    }

    if(ans.size()==0) cout<<"IMPOSSIBLE"<<endl;
    else{
        if(ans.size()<n)
            cout<<"IMPOSSIBLE"<<endl;
        else{
            for(auto a:ans)
                cout<<a<<" ";
        }

        cout<<endl;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    topo(n, adj, inDegree);
}

int32_t main()
{
    ios;
    int t = 1;
    while (t--)
        solve();
    return 0;
}