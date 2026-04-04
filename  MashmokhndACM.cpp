#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> factors(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j += i)
        {
            factors[j].push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}