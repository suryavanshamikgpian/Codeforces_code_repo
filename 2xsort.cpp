#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<pair<ll, ll>> prx;
    ll start = 0, end = 0;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] * 2 <= a[i - 1])
        {
            if (start != end)
            {
                prx.push_back({start, end});
            }
            start = i;
            end = i;
        }
        else
        {
            end = i - 1;
        }
    }
    if (start != end)
    {
        prx.push_back({start, end});
    }
    int ans = 0;
    for (auto &p : prx)
    {
        ll length = p.second - p.first + 1;
        if (length >= k)
        {
            ans += (length - k + 1);
        }
    }
    cout << ans << "\n";
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