#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && a[i][j] == '1')
            {
                bool direct = true;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j && a[i][k] == '1' && a[k][j] == '1')
                    {
                        direct = false;
                        break;
                    }
                }
                if (direct)
                {
                    ans.push_back({i, j});
                }
            }
        }
    }

    if (ans.size() != n - 1)
    {
        cout << "No\n";
        return;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < ans.size(); i++)
    {
        adj[ans[i].first].push_back(ans[i].second);
        adj[ans[i].second].push_back(ans[i].first);
    }

    vector<bool> vis(n, false);
    vector<int> q;
    q.push_back(0);
    vis[0] = true;
    int head = 0;

    while (head < q.size())
    {
        int u = q[head++];
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push_back(v);
            }
        }
    }

    if (q.size() != n)
    {
        cout << "No\n";
        return;
    }

    vector<vector<int>> check(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        check[i][i] = 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        check[ans[i].first][ans[i].second] = 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i][k] == 1 && check[k][j] == 1)
                {
                    check[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] - '0' != check[i][j])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}