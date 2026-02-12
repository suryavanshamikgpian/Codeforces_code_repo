#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // prefix sum: pref[i] = sum of a[0..i-1]
        vector<ll> pref(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + a[i];
        }
        ll maxol = pref[n]; // initial maxol is the total sum of the array
        for (ll l = 0; l < n; l++)
        {
            ll total_sum = pref[n];
            for (ll r = l; r < n; r++)
            {
                ll subtractable = pref[r + 1] - pref[l];                   // sum of a[l..r]
                ll sum = total_sum - subtractable + (r - l + 1) * (l + r); // total sum after subtracting a[l..r]
                maxol = max(maxol, sum);
            }
        }
        cout << maxol << "\n";
    }

    return 0;
}
