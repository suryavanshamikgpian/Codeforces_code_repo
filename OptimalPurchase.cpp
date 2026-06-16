#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if (3 * a <= b)
    {
        cout << n * a << "\n";
    }
    else
    {
        ll ans = (n / 3) * b;
        ll rem = n % 3;
        ans += min(rem * a, b);
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}