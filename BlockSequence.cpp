#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> dp(n + 1);
    dp[n] = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + 1;
        ll j = i + 1 + a[i];
        if (j <= n)
        {
            dp[i] = min(dp[i], dp[j]);
        }
    }
    cout << dp[0] << endl;
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