#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll opp = 0;
    ll left_max = a[0];

    for (ll i = 1; i < n; i++)
    {
        left_max = max(left_max, a[i - 1]);
        if (a[i] < left_max)
        {
            opp++;
        }
    }
    cout << opp << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
