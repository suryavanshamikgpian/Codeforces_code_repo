#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v1;
        vector<ll> v2;
        vector<ll> l(n);
        vector<ll> r(n);
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            v1.push_back(a);
        }
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            v2.push_back(a);
        }
        // normal max subarray sum
        ll curr = v1[0];
        ll maxsum = v1[0];
        for (ll i = 1; i < n; i++)
        {
            curr = max(v1[i], curr + v1[i]);
            maxsum = max(maxsum, curr);
        }
        if (k % 2 == 0)
        {
            cout << maxsum << endl;
        }
        else
        {
            l[0] = v1[0];
            r[n - 1] = v1[n - 1];

            for (ll i = 1; i < n; i++)
            {
                // max subarray sum from left
                // max subarray sum from right
                l[i] = max(v1[i], l[i - 1] + v1[i]);
                r[n - i - 1] = max(v1[n - i - 1], r[n - i] + v1[n - i - 1]);
            }

            ll ans = maxsum; //-3
            for (ll i = 0; i <= n - 1; i++)
            {
                ans = max(ans, l[i] + r[i] + v2[i] - v1[i]);
            }
            cout << ans << endl;
        }
    }
}
