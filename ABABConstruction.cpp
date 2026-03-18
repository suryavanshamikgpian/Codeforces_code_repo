#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool solver(int n, const string &t)
{
    const int INF = 1e9;
    int minL[2] = {0, INF};
    int maxL[2] = {0, -INF};

    for (int i = 0; i < n; i++)
    {
        int nextMinL[2] = {INF, INF};
        int nextMaxL[2] = {-INF, -INF};
        char c = t[i];

        for (int parity = 0; parity < 2; parity++)
        {
            if (minL[parity] > maxL[parity])
            {
                continue;
            }

            char leftChar = (parity == 0 ? 'A' : 'B');
            if (c == '?' || c == leftChar)
            {
                nextMinL[parity ^ 1] = min(nextMinL[parity ^ 1], minL[parity] + 1);
                nextMaxL[parity ^ 1] = max(nextMaxL[parity ^ 1], maxL[parity] + 1);
            }

            char rightChar = (((n - 1 - i + parity) & 1) == 0 ? 'A' : 'B');
            if (c == '?' || c == rightChar)
            {
                nextMinL[parity] = min(nextMinL[parity], minL[parity]);
                nextMaxL[parity] = max(nextMaxL[parity], maxL[parity]);
            }
        }

        minL[0] = nextMinL[0];
        minL[1] = nextMinL[1];
        maxL[0] = nextMaxL[0];
        maxL[1] = nextMaxL[1];

        if (minL[0] > maxL[0] && minL[1] > maxL[1])
        {
            return false;
        }
    }

    return (minL[0] <= maxL[0] || minL[1] <= maxL[1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tel;
    cin >> tel;
    while (tel--)
    {
        ll n;
        cin >> n;
        string t;
        cin >> t;
        for (char &c : t)
        {
            c = (char)toupper((unsigned char)c);
        }
        if (solver((int)n, t))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
