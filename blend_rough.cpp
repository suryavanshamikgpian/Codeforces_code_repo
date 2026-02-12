#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> p(n + 1), pos(n + 1), a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            pos[p[i]] = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> blocks;
        blocks.reserve(n);
        blocks.push_back(a[1]);
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[i - 1])
                blocks.push_back(a[i]);
        }

        bool ok = true;
        for (int i = 1; i < (int)blocks.size(); i++)
        {
            if (pos[blocks[i]] <= pos[blocks[i - 1]])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
