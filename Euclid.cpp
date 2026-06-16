#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());
    for (ll i = 2; i < n; i++)
    {
        if (b[i] != b[i - 2] % b[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << b[0] << " " << b[1] << endl;
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