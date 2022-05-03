#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dfs(ll city, ll &n, vector<ll> &curr, ll &minPrice, vector<bool> &visited, vector<vector<vector<ll>>> &prices, vector<ll> &dp)
{
    if (city == n)
    {
        ll sum = accumulate(curr.begin(), curr.end(), 0);
        ll maxel = *max_element(curr.begin(), curr.end());
        ll price = sum - maxel + (maxel / 2);
        minPrice = min(minPrice, price);
        return price;
    }

    if (dp[city] != LLONG_MAX)
        return dp[city];

    ll priceCurr = LLONG_MAX;

    for (auto ad : prices[city])
    {
        if (!visited[ad[0]])
        {
            visited[ad[0]] = true;
            curr.push_back(ad[1]);
            priceCurr = min(priceCurr, dfs(ad[0], n, curr, minPrice, visited, prices, dp));
            curr.pop_back();
            visited[ad[0]] = false;
        }
    }

    return dp[city] = priceCurr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;

    vector<vector<vector<ll>>> prices(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        prices[a].push_back({c, b});
        
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> disc(n + 1, LLONG_MAX);

    dist[1] = 0;

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    pq.push({0, 1, false}); // pushing {cost, destination node, discounted status}

    while (!pq.empty())
    {
        vector<ll> temp = pq.top();
        pq.pop();

        if (temp[2] == true && disc[temp[1]] < temp[0]) // if the distance for this node has already been updated, i.e. it has already been considered before in any path
            continue;
        else if (temp[2] == false && dist[temp[1]] < temp[0])
            continue;

        for (auto p : prices[temp[1]])
        {
            if (temp[2] == false)
            {
                if ((temp[0] + p[0] / 2) < disc[p[1]]) // relaxation for discounted current price, if not already discounted
                {
                    disc[p[1]] = temp[0] + (p[0] / 2);
                    pq.push({disc[p[1]], p[1], true});
                }
                if (temp[0] + p[0] < dist[p[1]]) // relaxation for non-discounted price, continuing with discounted status as false
                {
                    dist[p[1]] = temp[0] + p[0];
                    pq.push({dist[p[1]], p[1], false});
                }
            }
            if (temp[2] == true && temp[0] + p[0] < disc[p[1]]) // if already discounted before, can't discount anymore
            {
                disc[p[1]] = temp[0] + p[0];
                pq.push({disc[p[1]], p[1], true});
            }
        }
    }
    cout << disc[n] << endl; // printing discounted cost to nth node

    return 0;
}