#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll sleep = 0;
    ll block_until = -1; // cannot sleep until this index

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            block_until = i + k; // must stay awake for next k classes
        }
        else
        { // s[i] == '0'
            if (i > block_until)
            {
                sleep++; // allowed to sleep
            }
        }
    }

    cout << sleep << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}
