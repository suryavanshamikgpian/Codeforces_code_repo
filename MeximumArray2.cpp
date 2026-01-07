#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> arr(n, -1);
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        queries.push_back({x, y, z});
    }
    for (ll i = 0; i < q; i++)
    {
        ll x = queries[i][0];
        ll y = queries[i][1];
        ll z = queries[i][2];
        if (x == 1)
        {
            for (ll i = y - 1; i < z; i++)
            {
                arr[i] = k;
            }
        }
        else
        {
            for (ll i = y - 1; i < z; i++)
            {
                if (arr[i] == k)
                {
                    arr[i] = k + 1;
                }
                else
                {
                    arr[i] = i % k;
                }
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            arr[i] = k - 1;
        }
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
