#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> a(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        a[i].first = b[i + 1] - b[i];
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    ll ans = n;
    for (ll i = 0; i < n - k; i++)
    {
        ans += a[i].first - 1;
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