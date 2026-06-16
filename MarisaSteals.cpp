#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(3, 0);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x % 3]++;
    }
    ll pair = min(a[1], a[2]);
    ll onesleft = (a[1] - pair) / 3;
    ll twosleft = (a[2] - pair) / 3;
    cout << a[0] + pair + onesleft + twosleft << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}