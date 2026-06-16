#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a >= 0 ? a : -a;
}

void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2)
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