#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin); // input.txt se input
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;

        cin >> n;
        vector<ll> a(n), p(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        queue<ll> q;
        for (int i = 0; i < n; i++)
        {
            ll x = a[i];
            if (q.empty() || q.back() != x)
            {
                q.push(x);
            }
        }
        ll index = 0;
        while (!q.empty() && index < n)
        {
            if (p[index] == q.front())
            {
                q.pop();
            }
            index++;
        }
        if (q.empty())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
