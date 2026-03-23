#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll factor_of(ll n, ll f)
{
    ll count = 0;
    while (n % f == 0)
    {
        count++;
        n /= f;
    }
    return count;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll max_val = n * m;
    ll k = 1;
    ll two_count = factor_of(n, 2);
    ll five_count = factor_of(n, 5);
    ll ans = n;

    while (two_count > five_count && k * 5 <= m)
    {
        k *= 5;
        five_count++;
    }
    while (five_count > two_count && k * 2 <= m)
    {
        k *= 2;
        two_count++;
    }

    while (k * 10 <= m)
    {
        k *= 10;
    }
    k = k / 10;
    ans = n * k;
    cout << ans << "\n";
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