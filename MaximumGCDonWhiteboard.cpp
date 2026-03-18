#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
ll solve(vector<ll> &a, ll n, ll k, vector<ll> &freq)
{
    for (ll g = n; g >= 1; g--)
    {

        ll pos = freq[min(n, 4 * g - 1)];
        pos -= freq[g] - freq[g - 1];

        if (2 * g <= n)
        {
            pos -= freq[2 * g] - freq[2 * g - 1];
        }
        if (3 * g <= n)
        {
            pos -= freq[3 * g] - freq[3 * g - 1];
        }
        if (pos <= k)
        {
            return g;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            freq[i] += freq[i - 1];
        }
        cout << solve(a, n, k, freq) << "\n";
    }
}