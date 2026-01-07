#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> balance;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        balance[x]++;
    }
    ll score = 0;
    for (auto &it : balance)
    {
        ll x = it.first;
        ll cnt = it.second;
        if (cnt < x)
        {
            score += cnt;
        }
        else if (cnt > x)
        {
            score += (cnt - x);
        }
    }
    cout << score << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
