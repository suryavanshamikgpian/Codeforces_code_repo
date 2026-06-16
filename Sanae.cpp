#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    unordered_map<ll, ll> mx, my;
    set<ll> x, y;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        x.insert(a[i].first);
        y.insert(a[i].second);
    }
    sort(a.begin(), a.end());
    ll count = 0;
    for (int i = 0; i < mx.size(); i++)
    {
    }
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