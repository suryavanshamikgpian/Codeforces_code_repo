#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 32768;
vector<ll> dp(M, -1);
ll find_no_of_2_facctors(ll n)
{
    ll count = 0;
    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }
    return count;
}

ll fun(ll n, ll step)
{
    if (n % M == 0)
    {
        return step;
    }
    if (step > 15)
    {
        return LLONG_MAX;
    }
    ll count_2_factors = find_no_of_2_facctors(n);
    if (count_2_factors >= 15)
    {
        return step;
    }
    if (count_2_factors == 0)
    {
        return fun(n + 1, step + 1);
    }
    return min(15 - count_2_factors + step, fun(n + 1, step + 1)); // we need to add 1 to make it divisible by 2 and then we need to divide it by 2 until it becomes 1, so we need to add 15-count_2_factors to make it divisible by 2 and then we need to divide it by 2 until it becomes 1, so we need to add step to count the number of steps taken to make it divisible by 2 and then we need to divide it by 2 until it becomes 1
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = fun(n, 0);
        cout << ans << "\n";
    }

    return 0;
}
