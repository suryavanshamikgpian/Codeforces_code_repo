#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a;
    map<ll, ll> freq;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (freq[x] == 0)
        {
            a.push_back(x);
        }
        freq[x]++;
    }
    sort(a.begin(), a.end());
    ll maxol = a.end()[-1];
    vector<ll> b;
    b.push_back(maxol);
    for (ll i = 1; i < a.size(); i++)
    {
        b.push_back(a[i - 1]);
    }
    for (auto it : freq)
    {
        if (freq[it.first] > 1)
        {
            for (ll i = 0; i < freq[it.first] - 1; i++)
            {
                b.push_back(it.first);
            }
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    ll sum = 0;
    ll mex = 0;
    unordered_map<ll, ll> vis;
    for (ll i = 0; i < b.size(); i++)
    {
        vis[b[i]]++;
        while (vis.find(mex) != vis.end())
        {
            mex++;
        }
        // cout << mex << " ";
        sum = sum + mex;
    }

    sum = sum + (maxol * n);

    cout << sum << endl;
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