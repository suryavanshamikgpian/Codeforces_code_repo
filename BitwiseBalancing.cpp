#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// j-i = aj - ai

void solve(ll n, vector<ll> &a)
{
    ll count = 0;
    for (ll x = 1; x <= sqrt(n); x++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll i = j - (a[j] * x);
            if (i >= 0 && i < j && a[i] == x)
            {
                count++;
            }
        }
    }
    for (ll x = sqrt(n) + 1; x <= n; x++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll i = j - (a[j] * x);
            if (i >= 0 && i < j && a[i] == x)
            {
                count++;
            }
        }
    }
    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll b, c, d;
        cin >> b >> c >> d;
        string b_str = bitset<61>(b).to_string();
        string c_str = bitset<61>(c).to_string();
        string d_str = bitset<61>(d).to_string();
        string a = "";
        int flag = 1;
        for (int i = 1; i < 61; i++)
        {
            if (b_str[i] == '1' && c_str[i] == '1')
            {
                if (d_str[i] == '1')
                {
                    a.push_back('0');
                }
                else
                {
                    a.push_back('1');
                }
            }
            else if (b_str[i] == '0' && c_str[i] == '1')
            {
                if (d_str[i] == '1')
                {
                    flag = 0;
                    break;
                }
                else
                {
                    a.push_back('0');
                }
            }
            else if (b_str[i] == '1' && c_str[i] == '0')
            {
                if (d_str[i] == '1')
                {
                    a.push_back('0');
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if (d_str[i] == '1')
                {
                    a.push_back('1');
                }
                else
                {
                    a.push_back('0');
                }
            }
        }
        if (flag == 0)
        {
            cout << "-1\n";
            continue;
        }
        ll a_num = stoll(a, nullptr, 2);
        cout << a_num << "\n";
    }
    return 0;
}
