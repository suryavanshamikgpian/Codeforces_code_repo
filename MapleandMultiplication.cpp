#include <bits/stdc++.h>
using namespace std;

void solver(long long a, long long b)
{
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (b % a == 0 || a % b == 0)
    {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
    return;
}

void solve()
{
    long long a, b;
    cin >> a >> b;
    solver(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}