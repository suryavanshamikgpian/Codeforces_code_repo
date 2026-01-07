#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    for (ll i = 0; i < s.size() - 1; i++)
    {
        ll next = i + 1;
        if (s[i] == 'Y' && s[next] == 'Y')
        {
            cout << "NO\n";
            return;
        }
        if (s[i] + s[next] == 'N' + 'Y')
        {
            if (s[i] == 'Y')
            {
                s.erase(next, 1);
                i--;
            }
            else
            {
                s.erase(i, 1);
                i--;
            }
        }
        // if ((i + 2 < s.size()) && s[i] == 'Y' && s[next] == 'N' && s[i + 2] == 'Y')
        // {
        //     cout << "NO\n";
        //     return;
        // }
    }
    if (s.size() == 1)
    {
        cout << "YES\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
// YNY no
// NYN yes
// NYNN