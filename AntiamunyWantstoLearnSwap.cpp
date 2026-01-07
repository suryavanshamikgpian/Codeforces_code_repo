#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
void checker(ull l, ull r, const vector<ull> &a)
{
}

void solve()
{
    ull n, q;
    cin >> n >> q;
    vector<ull> a;
    for (ull i = 0; i < n; i++)
    {
        ull x;
        cin >> x;
        a.push_back(x);
    }
    while (q--)
    {
        ull l, r;
        cin >> l >> r;
        checker(l, r, a);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
