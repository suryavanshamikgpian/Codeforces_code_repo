#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long sum = 0;
    long long ans = 2e18;
    for (int i = 1; i <= n; ++i)
    {
        long long a;
        cin >> a;
        sum += a;
        ans = min(ans, sum / i);
        cout << ans << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
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