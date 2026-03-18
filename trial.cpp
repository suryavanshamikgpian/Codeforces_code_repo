#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        // Maintain the list of possible candidates for the missing number
        vector<ll> candidates;
        for (ll i = 1; i <= n; i++)
            candidates.push_back(i);

        // Maintain the list of active indices we can still query
        vector<ll> active_indices;
        for (ll i = 1; i <= n - 1; i++)
            active_indices.push_back(i);

        ll round = 0;

        // Run until we've isolated the exact missing number
        while (candidates.size() > 1 && round < 30)
        {
            ll expected_ones = 0;
            vector<ll> next_candidates1;
            vector<ll> next_candidates0;
            for (ll x : candidates)
            {
                if ((x >> round) & 1)
                {
                    expected_ones++;
                    next_candidates1.push_back(x);
                }
                else
                {
                    next_candidates0.push_back(x);
                }
            }

            ll actual_ones = 0;
            vector<ll> next_active_ones;
            vector<ll> next_active_zeros;

            for (ll idx : active_indices)
            {
                // Correctly use bitwise shift instead of pow()
                cout << "? " << idx << " " << (1LL << round) << endl;
                ll resp;
                cin >> resp;
                if (resp != 0)
                {
                    actual_ones++;
                    next_active_ones.push_back(idx);
                }
                else
                {
                    next_active_zeros.push_back(idx);
                }
            }

            // Compare actual vs expected to find the missing number's bit
            if (actual_ones < expected_ones)
            {
                // The missing number has a 1 at this bit
                active_indices = next_active_ones;
                candidates = next_candidates1;
            }
            else
            {
                // The missing number has a 0 at this bit
                active_indices = next_active_zeros;
                candidates = next_candidates0;
            }
            round++;
        }
        cout << "! " << candidates[0] << endl;
    }
    return 0;
}
