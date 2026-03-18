#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
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
        ll ans = 0;
        ll i = 0;
        while (i < n)
        {
            ll j = i + 1;
            while (j < n)
            {
                if (a[i] == a[j] || a[i] + a[j] == 7)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            ans = ans + ((j - i) / 2);
            i = j;
        }
        cout << ans << "\n";
    }
    return 0;
}