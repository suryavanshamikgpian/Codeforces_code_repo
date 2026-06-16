#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n, k, zeros = 0, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val == 0)
            zeros++;
    }

    vector<int> moves(n + 1, -1);
    queue<int> q;

    q.push(zeros);
    moves[zeros] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == 0)
        {
            cout << moves[0] << "\n";
            return;
        }
        for (int x = 0; x <= k && x <= curr; x++)
        {
            int y = k - x;
            if (y <= n - curr)
            {
                int next_zeros = curr - x + y;
                if (moves[next_zeros] == -1)
                {
                    moves[next_zeros] = moves[curr] + 1;
                    q.push(next_zeros);
                }
            }
        }
    }

    cout << -1 << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}