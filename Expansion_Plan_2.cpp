#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    x = llabs(x);
    y = llabs(y);

    for (char c : s)
    {
        if (c == '4')
        {
            if (x > y)
            {
                x = max(x - 1, 0LL);
            }
            else
            {
                y = max(y - 1, 0LL);
            }
        }
        else
        {
            x = max(x - 1, 0LL);
            y = max(y - 1, 0LL);
        }
    }
    cout << (x == 0 && y == 0 ? "YES\n" : "NO\n");
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
