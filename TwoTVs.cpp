#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 0});
        v.push_back({b, 1});
    }
    sort(v.begin(), v.end());
    ll tv_needed = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i].second == 0)
        {
            tv_needed++;
        }
        else
        {
            tv_needed--;
        }
        if (tv_needed > 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
