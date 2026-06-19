#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll final_sum = 0;
    int curr_min = INT_MAX;
    vector<ll> left_min;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        curr_min = min(curr_min, a);
        left_min.push_back(curr_min);
    }
    final_sum = accumulate(left_min.begin(), left_min.end(), 0);
    cout << final_sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}