#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int lastStart = n - m + 1;

        const int NEG = -1e9;

        vector<int> dp(lastStart + 2, NEG);

        dp[1] = (a[1] == 1);
        int best = dp[1];

        for (int i = 2; i <= lastStart; i++)
        {
            int k = i - a[i] + 1;

            if (1 <= k && k < i && dp[k] > NEG)
                dp[k]++;

            dp[i] = best + (a[i] == 1);

            best = max(best, dp[i]);

            if (1 <= k && k < i)
                best = max(best, dp[k]);
        }

        for (int i = lastStart + 1; i <= n; i++)
        {
            int k = i - a[i] + 1;

            if (1 <= k && k <= lastStart && dp[k] > NEG)
                dp[k]++;
        }

        int keep = 0;
        for (int r = 1; r <= lastStart; r++)
            keep = max(keep, dp[r]);

        cout << n - keep << '\n';
    }

    return 0;
}