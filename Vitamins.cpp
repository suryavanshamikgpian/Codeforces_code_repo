#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<pair<int, string>> items(n);
    for (int i = 0; i < n; ++i)
        cin >> items[i].first >> items[i].second;

    const ll INF = (ll)9e18;
    // dp[a][b][c] = min cost to have (A present? a : 0/1), (B present? b), (C present? c)
    ll dp[2][2][2];
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                dp[a][b][c] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        int price = items[i].first;
        string vitamins = items[i].second;
        bool hasA = (vitamins.find('A') != string::npos);
        bool hasB = (vitamins.find('B') != string::npos);
        bool hasC = (vitamins.find('C') != string::npos);
        ll newdp[2][2][2];
        // initialize newdp with current dp values
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                for (int c = 0; c < 2; c++)
                {
                    newdp[a][b][c] = dp[a][b][c];
                }
            }
        }
        // consider taking the current item and update newdp accordingly
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                for (int c = 0; c < 2; c++)
                {
                    int na = a | hasA;
                    int nb = b | hasB;
                    int nc = c | hasC;
                    newdp[na][nb][nc] = min(newdp[na][nb][nc], dp[a][b][c] + price);
                }
            }
        }

        // copy newdp back into dp (cannot swap built-in arrays)
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                for (int c = 0; c < 2; c++)
                {
                    dp[a][b][c] = newdp[a][b][c];
                }
            }
        }
    }
    if (dp[1][1][1] == INF)
    {
        cout << -1 << "\n";
        return;
    }
    else
    {
        cout << dp[1][1][1] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
