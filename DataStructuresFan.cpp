#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree
{
    vector<ll> xor0, xor1, lazy;
    int n;

    SegTree(int n) : n(n), xor0(4 * n), xor1(4 * n), lazy(4 * n) {}

    void push(int node, int start, int end)
    {
        if (lazy[node])
        {
            swap(xor0[node], xor1[node]);
            if (start != end)
            {
                lazy[2 * node] ^= 1;
                lazy[2 * node + 1] ^= 1;
            }
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, vector<ll> &a, string &s)
    {
        if (start == end)
        {
            xor0[node] = (s[start] == '0') ? a[start] : 0;
            xor1[node] = (s[start] == '1') ? a[start] : 0;
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, a, s);
            build(2 * node + 1, mid + 1, end, a, s);
            xor0[node] = xor0[2 * node] ^ xor0[2 * node + 1];
            xor1[node] = xor1[2 * node] ^ xor1[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (start > end || start > r || end < l)
            return;

        if (l <= start && end <= r)
        {
            lazy[node] ^= 1;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r);
        update(2 * node + 1, mid + 1, end, l, r);

        push(2 * node, start, mid);
        push(2 * node + 1, mid + 1, end);
        xor0[node] = xor0[2 * node] ^ xor0[2 * node + 1];
        xor1[node] = xor1[2 * node] ^ xor1[2 * node + 1];
    }

    ll query(int node, int start, int end, int l, int r, int g)
    {
        if (start > end || start > r || end < l)
            return 0;

        push(node, start, end);

        if (l <= start && end <= r)
        {
            return (g == 0) ? xor0[node] : xor1[node];
        }

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, g) ^
               query(2 * node + 1, mid + 1, end, l, r, g);
    }
};

void solve()
{
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string s;
    cin >> s;
    cin >> q;

    SegTree st(n);
    st.build(1, 0, n - 1, a, s);

    while (q--)
    {w
        int t;
        cin >> t;

        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            st.update(1, 0, n - 1, l, r);
        }
        else
        {
            int g;
            cin >> g;
            cout << st.query(1, 0, n - 1, 0, n - 1, g) << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
