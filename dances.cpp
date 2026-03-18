#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n = 0, m = 0;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    a[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ptr_a = 0;
    ll ptr_b = 0;
    ll pairs = 0;
    while (ptr_a < n && ptr_b < n)
    {
        if (a[ptr_a] < b[ptr_b])
        {
            pairs++;
            ptr_a++;
            ptr_b++;
        }
        else
        {
            ptr_b++;
        }
    }
    cout << n - pairs << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}