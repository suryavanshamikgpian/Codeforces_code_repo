#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll ans = 1;
    ll prev = 0;
    for (ll x : a)
    {
        if (x == 0)
            continue;

        ll diff = x - prev;
        ans = (ans * (diff + 1)) % MOD;
        prev = x;
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