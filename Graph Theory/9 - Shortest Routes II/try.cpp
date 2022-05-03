#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

void floydWarshall(vector<vector<ll>> & dist) // TC: O(N^3)
{
    for(ll k = 1; k< dist.size(); k++)
    {
        for(ll i = 1; i<dist.size(); i++)
        {
            for(ll j = 1; j<dist.size(); j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); //IMP: relaxation of edge from i node to j node, through the k node
            }
        }
    }
}

void solve()
{
    ll M = 1000000000000;
    ll n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,M));

    for(ll i = 0; i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        dist[a][a] = 0;
        dist[b][b] = 0;
        dist[a][b] = min(dist[a][b],c); //since roads are always undirected
        dist[b][a] = min(dist[b][a],c);
    }

    floydWarshall(dist);

    for(ll i = 0; i<q;i++)
    {
        ll u,v;
        cin>>u>>v;
        cout<<(dist[u][v]<M?dist[u][v]:-1)<<endl;
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