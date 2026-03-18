#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % 1000000007;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % 1000000007;
        y = y >> 1;
        x = (x * x) % 1000000007;
    }
    return res;
}

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
        ll n;
        cin >> n;
        ll MOD = 1000000007;
        vector<ll> a(n);
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s1 = (s1 + a[i]) % MOD;

            // Modulo the square before adding, and modulo the sum after adding
            ll square = (a[i] % MOD * a[i] % MOD) % MOD;
            s2 = (s2 + square) % MOD;
        }
        ll P = ((s1 * s1) % MOD - s2 + MOD) % MOD;
        ll Q = (n % MOD * (n - 1) % MOD) % MOD;

        ll expected = (P * power(Q, MOD - 2)) % MOD;
        cout << expected << "\n";
    }
    return 0;
}
