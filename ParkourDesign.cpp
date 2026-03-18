#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solver(ll x, ll y)
{
    ll target = (x - 2 * y) % 3;
    ll z = (x - 2 * y) / 3;
    if (target != 0 || z < 0 || x < 2 || x + 4 * y < 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        solver(x, y);
    }
    return 0;
}