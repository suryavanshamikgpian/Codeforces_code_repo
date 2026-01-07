#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, y, r;
    cin >> n >> y >> r;
    cout << ((y / 2) + r <= n ? (y / 2) + r : n) << "\n";
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
