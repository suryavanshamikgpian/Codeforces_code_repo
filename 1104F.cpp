#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5, NEG = -1e9;
int g[N], st[N];

int main()
{
    fill(g, g + N, NEG);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, top = 0, fl = 0, mx = NEG;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            int c = i - a[i];
            int ok = c >= max(0, i - m) && c <= min(i - 1, n - m);
            int oc = ok ? g[c] : NEG;
            int fc = i - 1 - m;
            if (fc >= 0 && fc <= n - m && g[fc] > fl)
                fl = g[fc];
            int gm = max(mx, fl);
            if (i - 1 <= n - m)
            {
                int v = (ok && c == i - 1) + gm;
                if (v > g[i - 1])
                {
                    if (g[i - 1] == NEG)
                        st[top++] = i - 1;
                    g[i - 1] = v;
                    mx = max(mx, v);
                }
            }
            if (ok)
            {
                int v = 1 + max(oc, fl);
                if (v > g[c])
                {
                    if (g[c] == NEG)
                        st[top++] = c;
                    g[c] = v;
                    mx = max(mx, v);
                }
            }
        }
        cout << n - max(g[n - m], fl) << "\n";
        while (top)
            g[st[--top]] = NEG;
    }
}
