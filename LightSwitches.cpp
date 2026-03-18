#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll max_a = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            max_a = max(max_a, a[i]);
        }

        ll period = 2 * k;
        // Difference array on circle of size period
        vector<int> diff(period + 1, 0);

        for (ll i = 0; i < n; i++)
        {
            ll r = a[i] % period;
            if (r + k <= period)
            {
                // No wrap: on-interval is [r, r+k-1]
                diff[r]++;
                if (r + k < period)
                    diff[r + k]--;
            }
            else
            {
                // Wraps: on-interval is [r, period-1] ∪ [0, (r+k-1)%period]
                diff[r]++;
                diff[0]++;
                diff[(r + k) % period]--;
            }
        }

        // Sweep prefix sums to find residues where all n lights are on
        ll best = LLONG_MAX;
        int cnt = 0;
        for (ll j = 0; j < period; j++)
        {
            cnt += diff[j];
            if (cnt == n)
            {
                // Find smallest t >= max_a with t % period == j
                ll rem = max_a % period;
                ll t_val;
                if (rem <= j)
                    t_val = max_a + (j - rem);
                else
                    t_val = max_a + (period - rem + j);
                best = min(best, t_val);
            }
        }

        if (best == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << best << "\n";
    }
    return 0;
}
