#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void solver(ll l, ll r, vector<pair<ll, ll>> &costing, ll &curr, vector<bool> &seen, ll p)
// {
//     cout << "Entering solver: l=" << l << ", r=" << r << ", curr=" << curr << endl;
//     if (seen[l])
//     {
//         return;
//     }
//     if (l > r)
//     {
//         return;
//     }
//     seen[l] = true;
//     ll cost = costing[l].first;
//     ll a = costing[l].second;
//     curr += cost;
//     for (ll i = 1; i <= a; i++)
//     {
//         ll x = l + i;
//         while (x > r && l + i > r)
//         {
//             i++;
//             x = l + i;
//         }
//         if (x <= r)
//         {
//             solver(x, r, costing, curr, seen, p);
//         }
//     }
//     return;
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<ll, ll>> costing;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            costing.push_back({x, a[i]});
        }
        sort(costing.begin(), costing.end());
        ll cost = p;
        ll already_shared = 1;
        for (ll i = 0; i < n; i++)
        {
            ll can_be_shared = costing[i].second;
            ll cost_of_sharing = costing[i].first;
            if (cost_of_sharing > p)
            {
                break;
            }
            if (already_shared + can_be_shared > n)
            {
                cost += (n - already_shared) * cost_of_sharing;
                already_shared = n;
            }
            else
            {
                cost += can_be_shared * cost_of_sharing;
                already_shared += can_be_shared;
            }
        }
        cout << cost << endl;
    }

    return 0;
}
