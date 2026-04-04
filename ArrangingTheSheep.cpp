#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n, total_sheeps = 0;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<ll, ll>> v; // {size, pos}
    vector<ll> pichei_wala; // gaps only between consecutive '*' clusters
    ll prev_cluster_end = -1;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            ll j = i;
            while (j < n && s[j] == '*')
                j++;

            ll cluster_size = j - i;
            total_sheeps += cluster_size;
            v.push_back({cluster_size, i});

            // store only gap between previous cluster and current cluster
            if (prev_cluster_end != -1)
                pichei_wala.push_back(i - prev_cluster_end);

            prev_cluster_end = j;
            i = j - 1;
        }
    }
    if (v.size() == 0 || v.size() == 1)
    {
        cout << "0\n";
        return;
    }
    ll median_sheep = (total_sheeps + 1) / 2, mm = (total_sheeps + 1) / 2, index = 0;

    while (mm > 0)
    {
        mm = mm - v[index].first;
        index++;
        if (mm <= 0)
        {
            mm = index - 1;
            median_sheep = mm;
            break;
        }
    }
    ll prev = 0, steps = 0;
    for (ll i = mm - 1; i >= 0; i--)
    {
        ll size = v[i].first;
        prev = pichei_wala[i] + prev;
        steps += prev * (size);
    }
    prev = 0;
    for (ll i = mm; i < pichei_wala.size(); i++)
    {
        ll size = v[i + 1].first;
        prev = pichei_wala[i] + prev;
        steps += prev * (size);
    }
    cout << steps << "\n";
}

signed main()
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
