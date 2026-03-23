#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;

    // Kept your exact map and input reading logic
    unordered_map<ll, vector<pair<ll, ll>>> mp;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> b(m);
        for (ll j = 0; j < m; j++)
        {
            cin >> b[j];
            mp[b[j]].push_back({i, j});
        }
    }

    ll ans = 0;

    // Iterating through your map just like before
    for (auto it : mp)
    {
        vector<pair<ll, ll>> v = it.second;
        ll k = v.size();

        // --- THE ONLY MAJOR CHANGE ---
        // Instead of nested loops, we separate the rows and cols from your pairs
        vector<ll> rows, cols;
        for (ll i = 0; i < k; i++)
        {
            rows.push_back(v[i].first);
            cols.push_back(v[i].second);
        }

        // Sort them independently
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        // Apply the fast math trick in a single loop
        for (ll i = 0; i < k; i++)
        {
            ans += rows[i] * i - rows[i] * (k - 1 - i);
            ans += cols[i] * i - cols[i] * (k - 1 - i);
        }
        // -----------------------------
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}