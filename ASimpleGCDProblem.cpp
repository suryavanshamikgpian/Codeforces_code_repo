#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    a = llabs(a);
    b = llabs(b);
    while (b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}