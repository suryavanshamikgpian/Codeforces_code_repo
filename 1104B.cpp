#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll moves = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        for (int j = i; j < n; j++)
        {
            if (a[j] <= b[i])
            {
                idx = j;
                break;
            }
        }
        if (idx == -1)
        {
            cout << -1 << endl;
            return;
        }
        for (int j = idx; j > i; j--)
        {
            swap(a[j], a[j - 1]);
        }
        moves += (idx - i);
    }
    cout << moves << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}