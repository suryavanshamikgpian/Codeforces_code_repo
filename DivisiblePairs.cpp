#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n), b(n);
        // vector<vector<ll>> dp(x, vector<ll>(y, 0));
        map<pair<ll, ll>, ll> dp; // Using map to handle large x and y
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = (a[i] % y + y) % y; // Ensure non-negative
            a[i] = (a[i] % x + x) % x; // Ensure non-negative
        }
        /*
        (a[i]%x + a[j]%x )%x =0
        ( a[i]% y)
        */
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            ll complement = (x - (a[i] % x)) % x;
            count += dp[{complement, b[i]}];
            dp[{a[i], b[i]}]++;
        }
        cout << count << "\n";
    }

    return 0;
}
