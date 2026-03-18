#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// j-i = aj - ai

void solve(ll n, vector<ll> &a)
{
    ll count = 0;
    for (ll x = 1; x <= sqrt(n); x++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll i = j - (a[j] * x);
            if (i >= 0 && i < j && a[i] == x)
            {
                count++;
            }
        }
    }
    for (ll x = sqrt(n) + 1; x <= n; x++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll i = j - (a[j] * x);
            if (i >= 0 && i < j && a[i] == x)
            {
                count++;
            }
        }
    }
    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, a);
    }
    return 0;
}
