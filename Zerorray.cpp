#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> counts;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll remainder = x % k;
        if (remainder != 0)
        {
            ll required = k - remainder;
            counts[required]++;
        }
    }
    if (counts.empty())
    {
        cout << 0 << "\n";
        return;
    }
    ll max_moves = 0;
    for (auto it : counts)
    {
        ll required = it.first;
        ll count = it.second;
        ll moves = required + (count - 1) * k;
        max_moves = max(max_moves, moves);
    }
    cout << max_moves + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}