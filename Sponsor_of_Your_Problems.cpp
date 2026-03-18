#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll l, ll r)
{
    string left = to_string(l);
    string right = to_string(r);
    ll n = left.size();
    ll start_index = 0;
    ll prev1st = 0, prev2nd = 0;
    for (int i = 0; i < left.size(); i++)
    {
        if (left[i] != right[i])
        {
            start_index = i;
            break;
        }
    }
    ll fun = 0;
    for (ll i = start_index; i < n; i++)
    {
        ll left_digit = left[i] - '0';
        ll right_digit = right[i] - '0';
        if (left_digit == right_digit)
        {
            fun++;
        }
        else if (right_digit - left_digit == 1)
        {
            fun += 2;
        }
    }
    cout << 2 * start_index + fun << "\n";
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
        ll l, r;
        cin >> l >> r;
        solve(l, r);
    }
}
