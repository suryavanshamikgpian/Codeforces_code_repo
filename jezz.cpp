#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(vector<vector<ll>> &v, ll l, ll r, ll k)
{
    ll val = 0;
    for (ll i = 30; i >= 0; i--)
    {
        if (v[r][i] - v[l - 1][i] == (r - l + 1))
        {
            val |= (1LL << i);
        }
    }
    return val >= k;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<vector<ll>> v(n + 1, vector<ll>(31, 0));
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (ll j = 0; j < 31; j++)
        {
            v[i][j] = v[i - 1][j] + (a[i] >> (j) & 1);
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;
        ll ans = -1, lo = l, hi = n;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (check(v, lo, mid, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}