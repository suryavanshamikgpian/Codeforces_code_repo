#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> parent;
vector<ll> sz;
ll find_parent(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]);
}
void union_sets(ll a, ll b)
{
    a = find_parent(a);
    b = find_parent(b);
    if (a != b)
    {
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (ll i = 0; i < m; i++)
    {
        ll k;
        cin >> k;

        if (k == 0)
            continue;

        ll first_person;
        cin >> first_person;
        for (ll j = 1; j < k; j++)
        {
            ll next_person;
            cin >> next_person;
            union_sets(first_person, next_person);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << sz[find_parent(i)] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}