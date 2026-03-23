#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= 2 * n; i = i + 2)
    {
        cout << "? " << i << " " << i + 1 << endl;
        ll x;
        cin >> x;
        if (x == 1)
        {
            cout << "! " << i + 1 << endl;
            cout.flush();
            return;
        }
    }
    return;
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