#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if (n % 2 == 1)
    {
        cout << "1\n";
        return;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1);
    cout << ans << '\n';
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