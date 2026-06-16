#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int min_moves = n;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && a[j] == a[i])
        {
            j++;
        }
        int L = i;
        int R = n - j;
        int moves = max(L, R);

        min_moves = min(min_moves, moves);
        i = j;
    }

    cout << min_moves << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
