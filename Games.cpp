#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> hash(101, 0);
    ll common = 0;
    vector<ll> a, b;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        hash[x]++;
    }
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        b.push_back(x);
        hash[x]++;
        if (hash[x] == 2)
        {
            common = x;
        }
    }
    auto it_a = lower_bound(a.begin(), a.end(), common);
    auto it_b = lower_bound(b.begin(), b.end(), common);
    ll idx_a = it_a - a.begin();
    ll idx_b = it_b - b.begin();
    ll choser_a = max(idx_a, n - idx_a - 1);
    ll choser_b = max(idx_b, m - idx_b - 1);
    if (choser_a < choser_b)
    {
        cout << 2 * choser_a + 1 << "\n";
    }
    else if (choser_b < choser_a)
    {
        cout << 2 * choser_b + 2 << "\n";
    }
    else
    {
        cout << 2 * choser_a + 1 << "\n";
    }
    return;

    // cout << idx_a << " " << idx_b << "\n";
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
