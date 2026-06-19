#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, maxol = INT_MIN;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        maxol = max(maxol, h[i]);
    }
    ll tar = maxol + 1;
    ll k = 0;
    for (ll i = 0; i < n; i++)
    {
        k = max(k, tar - h[i]);
    }
    cout << k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}