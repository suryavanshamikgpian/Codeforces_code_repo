#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        vector<ll> idx(n);
        for (ll i = 1; i <= n - 1; i++)
        {
            idx[i - 1] = i;
        }
        ll round = 0;
        while (round < 30)
        {
            ll expected_ones = 0;
            ll real_ones = 0;
            vector<ll> next_candidates1;
            vector<ll> next_candidates0;
            for (ll i = 1; i <= n - 1; i++)
            {
                if (a[i] & (1LL << round))
                {
                    real_ones++;
                }
            }
            round++;
        }
    }
}