#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> p(k);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
    }
    a[0] = a[n + 1] = a[p[0]];
    int max_region = 0, total = 0, curr_region = 0, p_idx = 0;

    for (int i = 0; i <= n; i++)
    {
        // cout<< curr_region<<endl;
        if (p_idx < k && i == p[p_idx])
        {
            max_region = max(max_region, curr_region);
            curr_region = 0;
            p_idx++;
        }
        if (a[i] != a[i + 1])
        {
            curr_region++;
            // cout<< i<<" "<<curr_region<<" "<<max_region<<endl;
            total++;
        }
    }
    max_region = max(max_region, curr_region);

    cout << max(total / 2, max_region) << '\n';
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