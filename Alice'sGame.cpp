#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], n, q;

int getMax(int *tree, int l, int r)
{
    int res = -2e9;
    for (l += n - 1, r += n; l < r; l /= 2, r /= 2)
    {
        if (l % 2)
            res = max(res, tree[l++]);
        if (r % 2)
            res = max(res, tree[--r]);
    }
    return res;
}

void solve()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[n + i];
    for (int i = 0; i < n; i++)
        cin >> b[n + i];

    for (int i = n - 1; i > 0; i--)
    {
        a[i] = max(a[i * 2], a[i * 2 + 1]);
        b[i] = max(b[i * 2], b[i * 2 + 1]);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (getMax(a, l, r) > getMax(b, l, r))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}