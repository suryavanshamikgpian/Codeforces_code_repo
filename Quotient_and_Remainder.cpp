#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> q(n), r(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    sort(q.begin(), q.end());
    sort(r.rbegin(), r.rend());
    ll ans = 0;
    ll j = 0;
    ll i = 0;
    while (i < n && j < n)
    {
        if ((q[i] + 1) * (r[j] + 1) - 1 <= k)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}