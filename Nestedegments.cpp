#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool seg(ll i, vector<pair<ll, ll>> &segments)
{
    ll l1 = segments[i].first;
    ll r1 = segments[i].second;
    ll l2 = segments[i + 1].first;
    ll r2 = segments[i + 1].second;
    return l1 <= l2 && r1 >= r2;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> segments(n);
    map<pair<ll, ll>, vector<ll>> pos;
    for (ll i = 0; i < n; i++)
    {
        cin >> segments[i].first >> segments[i].second;
        pos[segments[i]].push_back(i);
    }
    sort(segments.begin(), segments.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
         {
             if (a.first == b.first)
                 return a.second > b.second; 
             return a.first < b.first; });
    for (ll i = 0; i < n - 1; i++)
    {
        if (seg(i, segments))
        {
            if (segments[i] == segments[i + 1])
            {
                cout << pos[segments[i + 1]][0] + 1 << " " << pos[segments[i]][1] + 1 << endl;
            }
            else
            {
                cout << pos[segments[i + 1]][0] + 1 << " " << pos[segments[i]][0] + 1 << endl;
            }
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}