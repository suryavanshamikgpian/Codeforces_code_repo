#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<int> adj[num_nodes + 1];
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // -1 means not visited, 0 and 1 are the two "sides" or colors
    vector<int> side(num_nodes + 1, -1);
    long long total_beautiful = 0;

    for (int i = 1; i <= num_nodes; i++)
    {
        // If we haven't visited this group (component) yet
        if (side[i] == -1)
        {
            queue<int> todo;
            todo.push(i);
            side[i] = 0;

            bool can_be_bipartite = true;
            int count_side0 = 0;
            int count_side1 = 0;

            while (!todo.empty())
            {
                int current = todo.front();
                todo.pop();

                // Count how many nodes are on each side
                if (side[current] == 0)
                    count_side0++;
                else
                    count_side1++;

                for (int neighbor : adj[current])
                {
                    if (side[neighbor] == -1)
                    {
                        // Color the neighbor with the opposite side
                        side[neighbor] = 1 - side[current];
                        todo.push(neighbor);
                    }
                    else if (side[neighbor] == side[current])
                    {
                        // If a neighbor is on the same side, there's an odd cycle!
                        can_be_bipartite = false;
                    }
                }
            }

            // Only bipartite groups can have beautiful vertices
            if (can_be_bipartite)
            {
                // To maximize, we pick the larger side of the group
                total_beautiful += max(count_side0, count_side1);
            }
        }
    }
    cout << total_beautiful << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
    return 0;
}