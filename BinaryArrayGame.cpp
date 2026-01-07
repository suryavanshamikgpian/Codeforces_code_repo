#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    ll cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            cnt0++;
    }
    if ((cnt0 % 2) == 0 && cnt0 != 0)
    {
        cout << "BOB\n";
    }
    else
    {
        cout << "ALICE\n";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
// YNY no
// NYN yes
// NYNN