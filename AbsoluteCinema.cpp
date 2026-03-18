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

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> ans(n, 0);

        for (int j = 1; j < n - 1; j++)
        {
            ans[j] = (arr[j - 1] + arr[j + 1]) / 2 - arr[j];
        }

        long long s1 = 0, s2 = 0;

        for (int i = 1; i < n - 1; i++)
        {
            s1 += 1LL * i * ans[i];
            s2 += 1LL * (n - i - 1) * ans[i];
        }

        ans[0] = (arr[n - 1] - s2) / (n - 1);
        ans[n - 1] = (arr[0] - s1) / (n - 1);

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
