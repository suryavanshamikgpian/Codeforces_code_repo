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

    sort(a.begin(), a.end());

    ll maxol = a[n - 1];

    vector<ll> b(n);

    b[0] = maxol;

    for (ll i = 1; i < n; i++)
    {
        b[i] = a[i - 1];
    }

    ll sum = 0;
    ll mex = 0;

    vector<ll> vis(n + 2, 0);

    for (ll i = 0; i < b.size(); i++)
    {
        if (b[i] <= n)
        {
            vis[b[i]] = 1;
        }

        while (vis[mex])
        {
            mex++;
        }

        sum += mex;
    }

    sum = sum + (maxol * n);

    cout << sum << endl;
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