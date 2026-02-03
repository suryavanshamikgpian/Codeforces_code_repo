#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    DisjointSet ds(n);

    while (q--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 0)
        {
            ds.unionByRank(u, v);
        }
        else
        {
            cout << (ds.findUPar(u) == ds.findUPar(v) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}