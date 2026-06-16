#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s, s_new;
    cin >> s;
    ll n = s.size(), cut = 0;
    ll count[4] = {0};
    ll max_2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '4')
        {
            cut++;
        }
        else
        {
            s_new += s[i];
            count[s[i] - '0']++;
            if (s[i] == '2')
            {
                max_2 = s_new.size() - 1;
            }
        }
    }
    ll counter = 0;
    for (ll i = max_2; i >= 0; i--)
    {
        if (s_new[i] != '2')
        {
            counter++;
        }
    }

    cout << cut + min(counter, count[2]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}