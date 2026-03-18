#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll total_factor_of_a = m / a;
    ll total_factor_of_b = m / b;
    ll total_factor_of_c = m / c;
    ll total_factor_of_a_b = m / (a * b / gcd(a, b));
    ll total_factor_of_a_c = m / (a * c / gcd(a, c));
    ll total_factor_of_b_c = m / (b * c / gcd(b, c));
    ll total_factor_of_a_b_c = m / (a * b / gcd(a, b) * c / gcd(a * b / gcd(a, b), c));
    ll ans_a = 6 * (total_factor_of_a - total_factor_of_a_b - total_factor_of_a_c + total_factor_of_a_b_c);
    ans_a += 3 * (total_factor_of_a_b + total_factor_of_a_c - 2 * total_factor_of_a_b_c);
    ans_a += 2 * total_factor_of_a_b_c;
    ll ans_b = 6 * (total_factor_of_b - total_factor_of_a_b - total_factor_of_b_c + total_factor_of_a_b_c);
    ans_b += 3 * (total_factor_of_a_b + total_factor_of_b_c - 2 * total_factor_of_a_b_c);
    ans_b += 2 * total_factor_of_a_b_c;
    ll ans_c = 6 * (total_factor_of_c - total_factor_of_a_c - total_factor_of_b_c + total_factor_of_a_b_c);
    ans_c += 3 * (total_factor_of_a_c + total_factor_of_b_c - 2 * total_factor_of_a_b_c);
    ans_c += 2 * total_factor_of_a_b_c;
    cout << ans_a << " " << ans_b << " " << ans_c << "\n";
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