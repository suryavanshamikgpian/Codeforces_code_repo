#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<vector<ll>, ll>> child(n + 1);
    vector<ll> parent(n + 1, -1);
    ll root = 0;
    vector<pair<ll, ll>> prx(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        prx[i] = {x, y};
        if (x != -1)
        {
            child[x].first.push_back(i);
            child[x].second += y;
            parent[i] = x;
        }
        else
        {
            root = i;
        }
    }
    vector<ll> ans;
    for (ll i = 1; i <= n; i++)
    {
        if (i == root)
        {
            continue;
        }
        ll size_of_childrens = child[i].first.size();
        ll not_respect = child[i].second;
        if (size_of_childrens == not_respect)
        {
            if (prx[i].second == 1)
            {
                ans.push_back(i);
            }
        }
    }
    if (ans.empty())
    {
        cout << -1 << endl;
        return;
    }
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}