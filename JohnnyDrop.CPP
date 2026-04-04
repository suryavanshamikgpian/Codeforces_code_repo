#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll curr = n;
    while (curr > 0)
    {
        ans += curr;
        curr /= 2;
    }
    cout << ans << endl;
    return;
}

signed main()
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
