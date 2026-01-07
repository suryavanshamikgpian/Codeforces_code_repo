#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void rest_total(ll n, string s, ll nx, ll nv, ll ni, ll total)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            if (i == s.length() - 1)
            {
                if (ni > 0)
                {
                    total += 1;
                    ni--;
                }
                else if (nv > 0)
                {
                    total += 5;
                    nv--;
                }
                else if (nx > 0)
                {
                    total += 10;
                    nx--;
                }
                continue;
            }
            if (i < s.length() && s[i + 1] == '?')
            {
                if (ni >= 2)
                {
                    ni -= 2;
                    total += 2;
                }
                else if (ni == 1)
                {
                    if (nv > 0)
                    {
                        total += 4;
                        nv--;
                        ni--;
                    }
                    else
                    {
                        total += 9;
                        nx--;
                        ni--;
                    }
                }
                else if (ni == 0)
                {
                    if (nv >= 2)
                    {
                        nv -= 2;
                        total += 10;
                    }
                    else if (nv >= 1 && nx > 0)
                    {
                        total += 15;
                        nv--;
                        nx--;
                    }
                    else if (nx >= 2)
                    {
                        total += 20;
                        nx -= 2;
                    }
                }
                i++;
            }
            else if (i < s.length() && s[i + 1] != '?')
            {
                if (s[i + 1] == 'X')
                {
                    if (ni > 0)
                    {
                        total += 9;
                        ni--;
                    }
                    else if (nv > 0)
                    {
                        total += 5;
                        nv--;
                    }
                    else if (nx > 0)
                    {
                        total += 10;
                        nx--;
                    }
                }
                else if (s[i + 1] == 'V')
                {
                    if (ni > 0)
                    {
                        total -= 1;
                        ni--;
                    }
                    else if (nv > 0)
                    {
                        total += 5;
                        nv--;
                    }
                    else if (nx > 0)
                    {
                        total += 10;
                        nx--;
                    }
                }
                else if (s[i + 1] == 'I')
                {
                    if (ni > 0)
                    {
                        total += 1;
                        ni--;
                    }
                    else if (nv > 0)
                    {
                        total += 5;
                        nv--;
                    }
                    else if (nx > 0)
                    {
                        total += 10;
                        nx--;
                    }
                }
            }
            cout << "At index " << i << " total is " << total << endl;
        }
    }
    cout << total << endl;
    return;
}
ll solver(ll n, string s)
{
    int total = 0;
    // calculate total without '?'
    for (int i = 0; i < s.length(); i++)
    {
        cout << "total is " << total << endl;
        if (s[i] != '?')
        {
            if (s[i] == 'X')
            {
                total += 10;
            }
            else if (s[i] == 'V')
            {
                total += 5;
            }
            else if (s[i] == 'I' && i < n - 1 && (s[i + 1] == 'X' || s[i + 1] == 'V'))
            {
                total -= 1;
            }
            else if (s[i] == 'I' && i == n - 1)
            {
                total += 1;
            }
            else if (s[i] == 'I' && i < n - 1 && s[i + 1] != 'X' && s[i + 1] != 'V')
            {
                total += 1;
            }
        }
    }

    cout << "After non ? total is " << total << endl;
    cout << endl;

    return total;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll total_initial = solver(n, s);

    while (q--)
    {
        ll nx, nv, ni;
        cin >> nx >> nv >> ni;
        rest_total(n, s, nx, nv, ni, total_initial);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}