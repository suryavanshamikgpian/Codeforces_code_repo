#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, c = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == '(' || b[i] == '(')
        {
            c++;
        }
    }
    if (c != n)
    {
        cout << "NO\n";
        return;
    }
    ll x = 0, y = 0;

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '(')
            {
                x++;
                y++;
            }
            else
            {
                x--;
                y--;
            }
        }
        else
        {
        }
    }
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
/*

(((()) -> ((
()())) ->


*/