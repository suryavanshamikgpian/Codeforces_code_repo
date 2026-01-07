#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;

void solver(vector<vector<ll>> &adj, vector<ll> &a, ll n, ll m)
{
    ll res = 0;
    for (ll v = 1; v <= n; v++)
    {
        for (ll u : adj[v])
        {
                }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }

    solver(adj, a, n, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
