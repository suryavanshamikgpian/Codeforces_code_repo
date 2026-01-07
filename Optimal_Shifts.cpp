#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = s + s;
    n = 2 * n;
    ll curr = 0;
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            curr++;
            res = max(res, curr);
        }
        else
        {
            curr = 0;
        }
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
