#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<ll> blocksA;
    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            curr++;
        }
        else
        {
            if (curr > 0)
                blocksA.push_back(curr);
            curr = 0;
        }
    }
    if (curr > 0)
        blocksA.push_back(curr);

    vector<ll> blocksB;
    ll currb = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            currb++;
        }
        else
        {
            if (currb > 0)
                blocksB.push_back(currb);
            currb = 0;
        }
    }
    if (currb > 0)
        blocksB.push_back(currb);

    ll total_rectangles = 0;

    for (ll r = 1; r * r <= k; r++)
    {
        if (k % r == 0)
        {
            ll c = k / r;

            if (r <= n && c <= m)
            {
                ll waysA = 0, waysB = 0;
                for (ll len : blocksA)
                    if (len >= r)
                        waysA += (len - r + 1);
                for (ll len : blocksB)
                    if (len >= c)
                        waysB += (len - c + 1);
                total_rectangles += waysA * waysB;
            }

            if (r != c && c <= n && r <= m)
            {
                ll waysA = 0, waysB = 0;
                for (ll len : blocksA)
                    if (len >= c)
                        waysA += (len - c + 1);
                for (ll len : blocksB)
                    if (len >= r)
                        waysB += (len - r + 1);
                total_rectangles += waysA * waysB;
            }
        }
    }

    cout << total_rectangles << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}