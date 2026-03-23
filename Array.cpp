#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        ll a = 0, b = 0;
        for (ll j = i + 1; j < n; ++j)
        {
            if (s[j] > s[i])
            {
                a++;
            }
            else if (s[j] < s[i])
            {
                b++;
            }
        }
        cout << max(a, b) << " ";
    }
    cout << endl;
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