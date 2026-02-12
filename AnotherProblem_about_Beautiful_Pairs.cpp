#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        long long ans = 0;

        // i < j and a[i] * a[j] = j - i
        // j = i + a[i] * k  and a[j] = k
        for (int i = 1; i <= n; i++)
        {
            // j must be > i
            // k starts from 1
            for (int k = 1;; k++)
            {
                long long j = i + 1LL * a[i] * k;
                if (j > n)
                    break;
                if (a[j] == k)
                    ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
