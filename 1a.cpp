#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void print_array(vector<ll> &arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
}

signed main()

{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> p(n), max_amini(n);
        ll maxol = LLONG_MIN;
        vector<ll> bad_index_store;
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
            max_amini[i] = max(maxol, p[i]);
            maxol = max_amini[i];
            if (p[i] == maxol)
            {
                bad_index_store.push_back(i);
            }
        }

        ll p1 = bad_index_store[0];
        ll p2 = bad_index_store[bad_index_store.size() - 1];
        ll store = p[p1];
        p[p1] = p[p2];
        p[p2] = store;
        print_array(p);
    }
    return 0;
}
