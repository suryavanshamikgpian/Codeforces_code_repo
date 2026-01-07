#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());
        ll k = min<ll>(n, m);
        ll ans = 0;
        for (ll i = 0; i < k; ++i)
        {
            ans += a[i] * (m - i);
        }
        cout << ans << '\n';
    }
    return 0;
}
