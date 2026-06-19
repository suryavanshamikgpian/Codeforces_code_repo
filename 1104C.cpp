#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0, mx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    ll l = mx, r = sum, ans = sum;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll R = mid;
        bool ok = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > R)
            {
                ok = false;
                break;
            }
            R = max(a[i], R - a[i]);
        }

        if (ok)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
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