#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

signed main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        unordered_map<ll, ll> mp;
        bool flag = true;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                ll i;
                cin >> i;
                mp[i]++;
                if (mp[i] > (n * (n - 1)))
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << endl;
    }
    return 0;
}
