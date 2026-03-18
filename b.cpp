#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> cache(n + 1);
    ll maxol = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        maxol = max(maxol, v[i]);
        cache[v[i]].push_back(i);
    }

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (ll idx : cache[i])
    //         cout << idx << " ";
    //     cout << "\n";
    // }

    ll r = n;
    ll steps = 0;
    for (ll i = maxol; i >= 1 && r >= 0; i--)
    {
        vector<ll> &cur = cache[i];
        // cout << i << ": ";
        // for (ll idx : cur)
        //     cout << idx << " ";
        // cout << "\n";
        for (ll j = cur.size() - 1; j >= 0 && r >= 0; j--)
        {
            if (r > cur[j])
            {
                steps++;
                r = cur[j];
            }
        }
    }
    cout << steps << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}