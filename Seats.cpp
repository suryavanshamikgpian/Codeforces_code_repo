#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(string s, ll start, ll end, vector<bool> &v)
{
    // cout << "call hua hei " << start << " " << end << "\n";
    if (start > 0)
    {
        v[start] = false;
        start++;
    }
    if (end < s.length() - 1)
    {
        v[end] = false;
        end--;
    }
    if (start >= end)
    {
        return 0;
    }
    ll count = (end - start + 1) / 3 + (((end - start + 1) % 3) != 0 ? 1 : 0);
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        vector<bool> v(n, true);
        ll end = 0;
        if (n == 1 && s[0] == '0')
        {
            cout << 1 << "\n";
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                end = i;
                for (ll j = i + 1; j < n; j++)
                {
                    if (s[j] == '0')
                    {
                        end++;
                    }
                    else
                    {
                        break;
                    }
                }
                ans += calc(s, i, end, v);
                i = end;
            }
            else
            {
                v[i] = false;
                ans += 1;
                if ((i - 1) >= 0)
                {
                    v[i - 1] = false;
                }
                if ((i + 1) < n)
                {
                    v[i + 1] = false;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
