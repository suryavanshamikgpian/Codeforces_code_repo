#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solver(vector<ll> &a, ll n, ll k)
{
    vector<ll> d;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= a[0])
        {
            d.push_back(a[i + 1] - a[i]);
        }
    }
    sort(d.begin(), d.end());
    ll minimul = LLONG_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        if (minimul == 0)
            break;
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if (it != d.end())
        {
            minimul = min(minimul, abs((*it) - a[i]));
        }
    }
    for (int i = 0; i < d.size(); i++)
    {
        if (minimul == 0)
            break;
        auto it = lower_bound(a.begin(), a.end(), d[i]);
        if (it != a.end())
        {
            minimul = min(minimul, abs((*it) - d[i]));
        }
    }

    cout << minimul << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k >= 3)
        {
            cout << 0 << "\n";
        }
        else if (k == 2)
        {
            sort(a.begin(), a.end());
            solver(a, n, k);
        }
        else if (k == 1)
        {
            sort(a.begin(), a.end());
            ll minol = LLONG_MAX;
            for (int i = 0; i < n - 1; i++)
            {
                minol = min(minol, a[i + 1] - a[i]);
            }
            cout << minol << "\n";
        }
    }

    return 0;
}
