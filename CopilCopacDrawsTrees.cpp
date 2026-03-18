#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int to;
    int id;
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> dp(n + 1, 0);
    vector<int> parent_edge_idx(n + 1, 0);

    // BFS or DFS to propagate the readings
    // Using a simple BFS style with a queue or DFS
    vector<int> q;
    q.push_back(1);
    dp[1] = 1;
    parent_edge_idx[1] = 0; // The root has no parent edge, set to 0

    int head = 0;
    while (head < q.size())
    {
        int u = q[head++];
        for (auto &edge : adj[u])
        {
            int v = edge.to;
            int idx = edge.id;

            if (dp[v] == 0)
            { // if not visited
                if (idx >= parent_edge_idx[u])
                {
                    dp[v] = dp[u];
                }
                else
                {
                    dp[v] = dp[u] + 1;
                }
                parent_edge_idx[v] = idx;
                q.push_back(v);
            }
        }
    }

    int max_readings = 0;
    for (int i = 1; i <= n; i++)
        max_readings = max(max_readings, dp[i]);
    cout << max_readings << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}