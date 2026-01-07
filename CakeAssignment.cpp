#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void solve()
{
    ull k, x;
    cin >> k >> x;
    vector<ull> as;
    ull a = x;
    ull b = (1ULL << (k + 1)) - x;
    while (a != b)
    {
        if (a < b)
        {
            b -= a;
            a <<= 1;
            as.push_back(1);
        }
        else
        {
            a -= b;
            b <<= 1;
            as.push_back(2);
        }
    }

    cout << as.size() << '\n';
    for (ull i = as.size(); i-- > 0;)
        cout << as[i] << ' ';
    cout << '\n';
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
