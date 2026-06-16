#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    ll plane_dist = abs(x1 - x2);
    ll min_dist = min(plane_dist, n - plane_dist);
    if (n <= 3 || min_dist == 0)
    {
        cout << min_dist << endl;
        return;
    }
    cout << k + min_dist << endl;
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