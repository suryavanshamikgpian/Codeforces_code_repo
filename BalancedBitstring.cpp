#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool convertalll(ll i, ll n, ll k, string &s, char c)
{
    while (i < n)
    {
        if (s[i] != '?' && s[i] != c)
        {
            return true;
        }

        s[i] = c;
        i += k;
    }

    return false;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (ll i = 0; i < k; i++)
    {
        char c = '?';
        ll j = i;
        while (j < n)
        {
            if (s[j] != '?')
            {
                if (c == '?')
                {
                    c = s[j];
                }
                else if (c != s[j])
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            j += k;
        }
        if (c != '?')
        {
            bool flag = convertalll(i, n, k, s, c);
            if (flag)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    ll count0 = 0, count1 = 0;

    for (ll i = 0; i < k; i++)
    {
        if (s[i] == '0')
        {
            count0++;
        }
        else if (s[i] == '1')
        {
            count1++;
        }
    }

    if (count0 > k / 2 || count1 > k / 2)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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