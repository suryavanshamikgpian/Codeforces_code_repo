#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll r, g, b;
    cin >> r >> g >> b;
    ll n = r + g + b;
    ll last_r = -100, last_g = -100, last_b = -100;
    r = r > (n + 1) / 2 ? (n + 1) / 2 : r;
    g = g > (n + 1) / 2 ? (n + 1) / 2 : g;
    b = b > (n + 1) / 2 ? (n + 1) / 2 : b;

    vector<char> s(n, '?');
    ll maxol = max({r, g, b});
    if (r > 0 && maxol == r)
    {
        for (ll i = 0; i < n && r > 0; i = i + 2)
        {
            if (s[i] == '?')
            {
                s[i] = 'R';
                r--;
            }
        }
        for (ll i = 1; i < n; i++)
        {
            if (g > 0 && s[i] == '?' && (i - last_g == 2 || i - last_g > 3))
            {
                s[i] = 'G';
                g--;
                last_g = i;
            }
            else if (b > 0 && s[i] == '?' && (i - last_b == 2 || i - last_b > 3))
            {
                s[i] = 'B';
                b--;
                last_b = i;
            }
        }
    }
    else if (g > 0 && maxol == g)
    {
        for (ll i = 0; i < n && g > 0; i = i + 2)
        {
            if (s[i] == '?')
            {
                s[i] = 'G';
                g--;
            }
        }
        for (ll i = 1; i < n; i++)
        {
            if (r > 0 && s[i] == '?' && (i - last_r == 2 || i - last_r > 3))
            {
                s[i] = 'R';
                r--;
                last_r = i;
            }
            else if (b > 0 && s[i] == '?' && (i - last_b == 2 || i - last_b > 3))
            {
                s[i] = 'B';
                b--;
                last_b = i;
            }
        }
    }
    else if (b > 0 && maxol == b)
    {
        for (ll i = 0; i < n && b > 0; i = i + 2)
        {
            if (s[i] == '?')
            {
                s[i] = 'B';
                b--;
            }
        }
        for (ll i = 1; i < n; i++)
        {
            if (r > 0 && s[i] == '?' && (i - last_r == 2 || i - last_r > 3))
            {
                s[i] = 'R';
                r--;
                last_r = i;
            }
            else if (g > 0 && s[i] == '?' && (i - last_g == 2 || i - last_g > 3))
            {
                s[i] = 'G';
                g--;
                last_g = i;
            }
        }
    }
    char last = '?';
    // cout << b << " " << r << " " << g << "\n";
    while (b > 0 || r > 0 || g > 0)
    {
        if (b > 0)
        {
            cout << "B";
            b--;
        }
        else if (r > 0)
        {
            cout << "R";
            r--;
        }
        else if (g > 0)
        {
            cout << "G";
            g--;
        }
    }
    cout << s[0];
    last = s[0];
    for (ll i = 1; i < n; i++)
    {
        if (s[i] != '?' && s[i] != last)
        {
            cout << s[i];
            last = s[i];
        }
    }
    cout << "\n";
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