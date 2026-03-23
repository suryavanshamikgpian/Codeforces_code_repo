#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> s(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    vector<ll> dp(n + 1, 1);
    ll ans = 1;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = i * 2; j <= n; j += i)
        {
            if (s[j] > s[i])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
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