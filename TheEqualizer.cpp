#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        sum += a;
    }

    if (sum % 2 != 0 || (n * k) % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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