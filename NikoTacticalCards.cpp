#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    ll mi = 0, mx = 0;

    for (ll i = 0; i < n; i++)
    {
        ll min_val = min(mi - a[i], b[i] - mx);
        ll max_val = max(mx - a[i], b[i] - mi);
        mi = min_val;
        mx = max_val;
    }
    cout << mx << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
