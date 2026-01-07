#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = i * n + j + 1;
            if (i - 1 >= 0)
            {
                x += (i - 1) * n + j + 1;
            }
            if (j - 1 >= 0)
            {
                x += i * n + j;
            }
            if (i + 1 < n)
            {
                x += (i + 1) * n + j + 1;
            }
            if (j + 1 < n)
            {
                x += i * n + j + 2;
            }
            m = max(m, x);
        }
    }
    cout << m << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
