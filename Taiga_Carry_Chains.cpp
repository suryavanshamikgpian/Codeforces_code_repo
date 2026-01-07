#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solver(ll n, ll k)
{
    if (k == 0)
    {
        return 0;
    }
    ll x = n;
    ll pos = 0;
    vector<ll> bits;
    while (x > 0)
    {
        bits.push_back(x % 2);
        x /= 2;
    }
    ll most_number_of_1s = 0;
    ll start = 0;
    for (ll i = 0; i < bits.size(); i++)
    {
        if (bits[i] == 1)
        {
            ll current_number_of_1s = 0;
            for (ll j = i; j < bits.size(); j++)
            {
                if (bits[j] == 1)
                {
                    current_number_of_1s++;
                }
                else
                {
                    break;
                }
            }
            if (current_number_of_1s > most_number_of_1s)
            {
                most_number_of_1s = current_number_of_1s;
                start = i;
            }
        }
    }
    ll new_n = n + (1LL << start);
    return most_number_of_1s + solver(new_n, k - 1);
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll x = n;
    vector<ll> initial_bits;
    while (x > 0)
    {
        initial_bits.push_back(x % 2);
        x /= 2;
    }

    cout << solver(n, k) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
