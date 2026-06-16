#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (ll i = 0; i < n; i++)
    {
        vector<int> w(n, 0);
        ll sum = 0;
        ll prev = (i - 1 + n) % n;
        ll j = prev;
        while (j != i)
        {
            ll next = (j + 1) % n;
            if (h[next] > w[next])
            {
                w[j] = h[next];
            }
            else
            {
                w[j] = w[next];
            }
            sum += w[j];
            j = (j - 1 + n) % n;
        }
        cout << "w is :";
        for (ll i = 0; i < n; i++)
        {
            cout << w[i] << " ";
        }
        cout << endl;
        cout << sum;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}