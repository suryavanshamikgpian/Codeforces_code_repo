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
        vector<vector<ll>> a(n);
        for (ll i = 0; i < n; i++)
        {
            ll m;
            cin >> m;
            a[i].resize(m);
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
            reverse(a[i].begin(), a[i].end());
        }
        sort(a.begin(), a.end());
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     reverse(a[i].begin(), a[i].end());
        // }
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < a[i].size(); j++)
            {
                if (mp[a[i][j]] == 0)
                {
                    mp[a[i][j]] = 1;
                    cout << a[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
