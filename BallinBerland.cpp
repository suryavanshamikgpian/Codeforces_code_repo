#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> u(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    vector<ll> s(n);
    vector<pair<ll, ll>> v(n); //{skills , university}
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        v[i] = {s[i], u[i]};
    }
    sort(v.rbegin(), v.rend());
    unordered_map<ll, vector<ll>> mp;

    for (ll i = 0; i < n; i++)
    {
        ll uni = v[i].second;
        ll skill = v[i].first;
        if (mp[uni].size() == 0)
        {
            mp[uni].push_back(skill);
        }
        else
        {
            mp[uni].push_back(mp[uni].back() + skill);
        }
    }
    vector<ll> ans(n + 1, 0);
    for (auto it : mp)
    {
        ll sz = it.second.size();
        for (ll k = 1; k <= sz; k++)
        {
            ll take = (sz / k) * k;
            if (take > 0)
            {
                ans[k] += it.second[take - 1];
            }
        }
    }

    for (ll k = 1; k <= n; k++)
    {
        cout << ans[k] << " ";
    }
    cout << "\n";
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