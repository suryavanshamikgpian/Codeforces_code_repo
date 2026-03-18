#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> freq(11, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        for (ll i = 10; i >= 0; i--)
        {
            if (freq[i] > 0)
            {
                cout << freq[i] << "\n";
                break;
            }
        }
    }
    return 0;
}
