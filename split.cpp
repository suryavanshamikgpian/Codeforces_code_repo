#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    ll total = 0;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 0; i < 2 * n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    ll space1 = n, space2 = n;
    for (auto it : mp)
    {
        if (it.second % 2)
        { // odd }
            ans++;
            space1 -= it.second / 2;             // 4
            space2 = space2 - it.second / 2 - 1; // 3
        }
        else
        {
            if ((it.second / 2) % 2)
            { // odd
                space1 -= it.second / 2;
                space2 -= it.second / 2;
                ans += 2;
                continue;
            }
            else
            {
                if (space1 >= (it.second / 2 + 1))
                {
                    space1 -= (it.second / 2 + 1);
                    space2 -= (it.second / 2 - 1);
                    ans += 2;
                }
                else if (space2 >= (it.second / 2 + 1))
                {
                    space2 -= (it.second / 2 + 1);
                    space1 -= (it.second / 2 - 1);
                    ans += 2;
                }
                else
                {
                    space1 -= it.second / 2;
                    space2 -= it.second / 2;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
