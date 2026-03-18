#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<vector<int>> &v, int l, int r, int k)
{
    int val = 0;

    for (int j = 30; j >= 0; j--)
    {
        int ones = v[r][j] - v[l - 1][j];

        if (ones == (r - l + 1))
            val |= (1LL << j);
    }

    return val >= k;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> v(n + 1, vector<int>(31));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            v[i][j] = v[i - 1][j] + ((a[i] >> j) & 1);
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, k;
        cin >> l >> k;

        int lo = l, hi = n, ans = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (check(v, l, mid, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        cout << ans << " ";
    }

    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}