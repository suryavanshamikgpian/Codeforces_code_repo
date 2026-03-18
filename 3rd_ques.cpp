#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i] >> p[i];
    }

    double dp = 0.0;

    for (int i = n - 1; i >= 0; --i)
    {
        double not_take = dp;
        double take = c[i] + (1.0 - p[i] / 100.0) * dp;

        dp = max(not_take, take);
    }

    cout << fixed << setprecision(10) << dp << "\n";
}

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}