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
    cout.tie(NULL);
    ll MOD = 998244353LL;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> p(n), q(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        vector<ll> dp(n);
        ll num = 1;
        for (ll i = 0; i < n; i++)
        {
            dp[i] = num % MOD;
            num = num * 2;
            num %= MOD;
        }
        vector<ll> r(n);
        ll pmax = -1, qmax = -1, pmaxi = -1, qmaxi = -1;
        for (ll i = 0; i < n; i++)
        {
            pmax = max(pmax, p[i]);
            if (pmax == p[i])
            {
                pmaxi = i;
            }
            qmax = max(qmax, q[i]);
            if (qmax == q[i])
            {
                qmaxi = i;
            }

            if (pmax > qmax)
            {
                r[i] = (ll)(dp[pmax] + dp[q[i - pmaxi]]) % MOD;
            }
            else if (pmax < qmax)
            {
                r[i] = (ll)(dp[qmax] + dp[p[i - qmaxi]]) % MOD;
            }
            else
            {
                if (p[i - qmaxi] >= q[i - pmaxi])
                {
                    r[i] = (ll)(dp[p[i - qmaxi]] + dp[qmax]) % MOD;
                }
                else
                {
                    r[i] = (ll)(dp[q[i - pmaxi]] + dp[pmax]) % MOD;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cout << r[i] << " ";
        }
        cout << "\n";
    }
}