#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll solver(ll i, ll k, vector<ll> &a, vector<ll> &wake, vector<ll> &dp)
// {
//     if (i < 0)
//         return 0LL;
//     if (dp[i] != -1)
//         return dp[i];
//     ll not_woke = solver(i - 1, k, a, wake, dp);
//     const ll NEG_INF = -(1LL << 60);
//     ll woke = NEG_INF;
//     if (i - k >= 0)
//         woke = accumulate(a.begin() + max(0LL, i - k), a.begin() + i + 1, 0LL) + solver(i - k - 1, k, a, wake, dp);

//     dp[i] = max(not_woke, woke);
//     return dp[i];
// }
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> wake(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < n; i++)
    {
        cin >> wake[i];
    }
    vector<ll> dp(n, -1);
    if (k >= n)
    {
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
        return;
    }
    vector<ll> suffix_sum(n, -1);
    suffix_sum[n - 1] = (wake[n - 1] == 1) ? a[n - 1] : 0;
    // Precompute suffix sums of awake values
    for (int i = n - 2; i >= 0; i--)
    {
        if (wake[i] == 1)
            suffix_sum[i] = a[i] + suffix_sum[i + 1];
        else
            suffix_sum[i] = suffix_sum[i + 1];
    }
    ll maxol = LLONG_MIN;
    ll prev = 0;
    for (int i = 0; i < k; i++)
    {
        prev += a[i];
    }
    maxol = max(maxol, prev + suffix_sum[k]);
    for (int i = 1; i < n - k; i++)
    {
        prev -= a[i - 1];
        prev += a[i + k - 1];
        maxol = max(maxol, prev + suffix_sum[i + k]);
    }
    cout << maxol << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
