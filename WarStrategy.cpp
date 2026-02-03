#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (k - 1 < n - k)
    {
    }
    vector<ll> a(n, 0);
    a[k - 1] = 1;
    bool turn = true;
    for (ll i = 1; i <= m; i++)
    {
        ll left = k - 2;
        if (turn)
        {
            // left side
            turn = false;
            for (ll j = k - 2; j >= 0; j--)
            {
                if (a[j] == 0)
                {
                }
            }
            // if (k - 2 >= 0)
            // {
            // }
        }
        if (!turn)
        {
            // right side
            turn = true;
            if ()
            {
            }
        }
        a[k - 1]++;
    }
    ll nelson = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            nelson++;
        }
    }
    cout << nelson << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
// YNY no
// NYN yes
// NYNN