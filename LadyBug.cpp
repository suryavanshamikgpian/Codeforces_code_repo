#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int u1 = 0, u2 = 0;
    int l1 = 0, l2 = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == '1')
        {
            u1++; // one count
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        if (b[i] == '0')
        {
            l1++; // zero count
        }
    }

    for (int i = 1; i < n; i += 2)
    {
        if (a[i] == '1')
        {
            u2++; // one count
        }
    }
    for (int i = 0; i < n; i += 2)
    {
        if (b[i] == '0')
        {
            l2++; // zero count
        }
    }

    if (u1 <= l1 && u2 <= l2)
    {
        cout << "YES" << "\n";
        return;
    }
    else
    {
        cout << "NO" << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
}