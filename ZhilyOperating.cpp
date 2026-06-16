#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll count = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i > 0 && a[i] >= 0)
        {
            a[i - 1] = a[i - 1] + a[i];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            count++;
        }
    }
    cout << count << endl;
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