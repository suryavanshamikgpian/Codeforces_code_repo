#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void see(string s, string t, ll n, ll j, vector<pair<ll, ll>> &v)
{
    if (j == n || s == t)
    {
        return;
    }
    ll k = j;
    for (ll i = j; i < n; i++)
    {
        if (s[i] != t[i])
        {
            k = i;
            if (i == n - 1)
            {
                v.push_back({j, k + 1});
            }
        }
        if (s[i] == t[i])
        {
            k = i;
            v.push_back({j, k});
            see(s, t, n, k + 1, v);
            break;
        }
    }
    return;
}
void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pair<ll, ll>> v;
    see(s, t, n, 0, v);
    cout << v.size() << "\n";
    for (auto it : v)
    {
        cout << it.first + 1 << " " << it.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
