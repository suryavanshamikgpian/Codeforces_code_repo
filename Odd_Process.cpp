#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> even, odd;
    vector<ll> kelser(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    if (odd.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << kelser[i] << " ";
        }
        cout << "\n";
        return;
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    ll coins_left = n;
    kelser[0] = odd[odd.size() - 1];
    if (even.size() == 0)
        kelser[1] = 0;

    for (ll k = 1; k <= even.size(); k++)
    {
        kelser[k] = kelser[k - 1] + even[even.size() - k];
    }
    if (odd.size() > 1)
    {
        for (ll k = even.size() + 1; k < n; k++)
        {
            if (k - 2 < 0)
            {
                kelser[k] = 0;
                continue;
            }
            kelser[k] = kelser[k - 2];
        }
    }
    if (sum % 2 == 0)
    {
        kelser[n - 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << kelser[i] << " ";
    }
    cout << "\n";
    return;
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

// 4 1 3 1 2

//     {2, 4} {1, 1, 3}

// 3 7 9 7 9