#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    map<ll, ll> freq;
    set<ll> s, t;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        t.insert(arr[i]);
        freq[arr[i]]++;
    }
    vector<ll> v;
    while (!s.empty())
    {
        auto x = *s.begin();
        v.emplace_back(x);
        for (ll i = x; i <= k; i += x)
        {
            if (t.count(i))
            {
                s.erase(i);
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << v.size() << "\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
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
