#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solver(vector<ll> &a)
{
    stack<ll> s, t;
    ll ans = 0;
    s.push(a[0]);
    ll x, y;
    for (int i = 1; i < a.size(); i++)
    {
        ll s_top = s.top();
        ll t_top = t.empty() ? 1e18 : t.top();
        if (a[i] > s_top && a[i] > t_top)
        {
            if (s_top < t_top)
            {
                s.push(a[i]);
            }
            else
            {
                t.push(a[i]);
            }
            ans++;
        }
        else if (s_top >= a[i])
        {
            s.push(a[i]);
        }
        else if (t_top >= a[i])
        {
            t.push(a[i]);
        }
        else
        {
            if (s_top < t_top)
            {
                s.push(a[i]);
            }
            else
            {
                t.push(a[i]);
            }
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solver(a) << endl;
    return;
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
