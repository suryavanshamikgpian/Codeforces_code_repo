#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n * (n + 1) / 2;

    vector<ll> cnt(3, 0);
    cnt[0] = 1;

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int val = (s[i] == '0' ? 1 : 2);
        sum = (sum + val) % 3;
        cnt[sum]++;
    }

    for (int i = 0; i < 3; i++)
    {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
    }

    ll len = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            len++;
        }
        else
        {
            if (len >= 3)
            {
                ans -= ((len - 1) / 2) * (len / 2);
            }
            len = 1;
        }
    }

    if (len >= 3)
    {
        ans -= ((len - 1) / 2) * (len / 2);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}