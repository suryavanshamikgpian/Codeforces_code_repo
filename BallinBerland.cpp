#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    vector<ll> a(k), b(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> b[i];
    }
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