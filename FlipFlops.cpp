#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++)
    {
        if (c >= a[i])
        {
            ll canadd = c - a[i];
            canadd = min(canadd, k);
            a[i] = a[i] + canadd;
            c = c + a[i];
            k = k - canadd;
        }
    }
    cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}