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
        ll n;
        cin >> n;
        unordered_map<ll, ll> array_to_store_factor_count;
        ll k = 1;
        for (ll i = 2; n != 1; i++)
        {
            // cout << "im here\n";
            bool flag = false;
            while (n != 1 && (n % i) == 0)
            {
                flag = true;
                n = n / i;
            }
            if (flag)
            {
                k = k * i;
            }
            if (i > sqrt(n) + 1)
            {
                k = k * n;
                break;
            }
        }
        cout << k << "\n";
    }
    return 0;
}
