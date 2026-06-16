#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, max_time = 0;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        max_time = max(max_time, abs(a[i].second - a[i].first));
    }
    ll greet = 0;
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll a1 = a[i].first, a2 = a[j].first, b1 = a[i].second, b2 = a[j].second;
            if ((a1 < a2 && b2 < b1) || (a1 > a2 && b2 > b1))
            {
                greet++;
            }
        }
    }
    cout << greet << '\n';
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