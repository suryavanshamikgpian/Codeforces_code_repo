#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, p = 1, neg = 0, pos = 1;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x < 0)
            p *= -1;
        if (p == -1)
            neg++;
        else
            pos++;
    }
    cout << pos * neg << " " << pos * (pos - 1) / 2 + neg * (neg - 1) / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}