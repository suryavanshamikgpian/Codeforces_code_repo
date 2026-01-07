#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll pos_element_count = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            pos_element_count++;
            sum += a[i];
        }
    }
    ll ans = pos_element_count;
    ll remaining_sum = sum - pos_element_count;
    if (n - 1 > remaining_sum)
    {
        ll dif = n - 1 - remaining_sum;
        ans -= dif;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}