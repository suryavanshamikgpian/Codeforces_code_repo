#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool is_sorted = true;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1])
        {
            is_sorted = false;
        }
    }
    if (is_sorted)
    {
        cout << n << "\n";
    }
    else
    {
        cout << 1 << "\n";
    }
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}