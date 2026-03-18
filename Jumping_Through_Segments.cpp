#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll checker(vector<pair<ll, ll>> &a, ll k)
{
    ll pos = 0;
    ll prev_min = 0;
    ll prev_max = 0;
    ll i = 0;
    while (i < a.size())
    {
        ll left = a[i].first;
        ll right = a[i].second;
        ll min_jump = prev_min - k;
        ll max_jump = prev_max + k;
        // Check if [min_jump, max_jump] overlaps with [left, right]
        if (max_jump < left || min_jump > right)
        {
            // No overlap at all
            return -1;
        }
        // Compute the overlap
        prev_min = max(min_jump, left);
        prev_max = min(max_jump, right);
        i++;
    }

    return 0;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ll l = 0, r = 1e9;
    ll mid;
    ll ans = 1e9;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        ll check = checker(a, mid);
        if (check == -1)
        {
            l = mid + 1;
        }
        else if (check == 0)
        {
            ans = min(ans, mid);
            r = mid;
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
