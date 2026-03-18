#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    set<pair<ll, ll>> s;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> parent(n + 1, -1); // Array to remember our path
    dist[1] = 0;
    s.insert({0, 1});
    while (!s.empty())
    {
        auto it = s.begin();
        ll u = it->second;
        ll dis = it->first;
        s.erase(it);
        for (int i = 0; i < adj[u].size(); i++)
        {
            ll v = adj[u][i].first;
            ll w = adj[u][i].second;
            if (dis + w <= dist[v])
            {
                if (dist[v] != LLONG_MAX)
                {
                    s.erase({dist[v], v});
                }
                dist[v] = dis + w;
                parent[v] = u; // Record that we reached 'v' from 'u'
                s.insert({dist[v], v});
            }
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (dist[i] == LLONG_MAX)
    //     {
    //         cout << -1 << " ";
    //     }
    //     else
    //     {
    //         cout << dist[i] << " ";
    //     }
    // }
    if (dist[n] == LLONG_MAX)
    {
        cout << -1 << "\n";
        return;
    }

    // Reconstruct the path by backtracking from 'n'
    vector<ll> path;
    for (ll curr = n; curr != -1; curr = parent[curr])
    {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end()); // Reverse to get the correct order from 1 to n
    for (ll node : path)
    {
        cout << node << " ";
    }
    cout << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
