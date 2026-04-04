#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<ll> marked(n + 1, 0);
    ll index = 0;
    ll count = 0;
    while (index < n)
    {
        if (p[index] <= index + 1 && marked[index + 1] != 1)
        {
            // cout << index << " " << p[index] << '\n';
            count++;
            marked[p[index]] = 1;
        }
        else if (marked[index + 1] == 1)
        {
            break;
        }
        index++;
    }
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}