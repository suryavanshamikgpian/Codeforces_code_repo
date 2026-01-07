#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solver(string &s, vector<ll> &broken, ll i)
{
    ll ans = 0;
    ll count = 0;
    for (ll j = 0; j < s.size(); j++)
    {
        if (broken[s[j] - 'a'] == 1)
        {
            count++;
        }
        else
        {
            ans += (count * (count + 1)) / 2;
            count = 0;
        }
    }
    ans += (count * (count + 1)) / 2;
    return ans;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> broken(26, 0);
    for (ll i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        broken[c - 'a'] = 1;
    }

    cout << solver(s, broken, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
