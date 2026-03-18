#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void print_array(vector<ll> &arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
}
void func(ll n)
{
    if (n == 4)
    {
        cout << 2 << " " << 1 << " " << 3 << " " << 4 << " ";
        return;
    }
    if (n == 6)
    {
        cout << 1 << " " << 2 << " " << 4 << " " << 6 << " " << 5 << " " << 3 << " ";
        return;
    }
    int x = (1 << ((int)log2(n)));
    // cout << "x: " << x << "\n";
    for (int i = 4; i < x - 2; i++)
        cout << i << " ";
    for (int i = x + 1; i <= n; i++)
        cout << i << " ";
    cout << 2 << " " << 1 << " " << 3 << " " << x - 2 << " " << x - 1 << " " << x << " ";
    return;
}
void solve(ll n, vector<ll> &ans)
{
    if (n % 2 == 1)
    { // odd
        cout << n << "\n";
        func(n - 1);
        cout << n << " ";
    }
    else
    {
        int x = 0;
        x = 1 << ((int)log2(n) + 1);
        cout << --x << "\n";
        func(n);
    }
    cout << endl;
    // ll curr = 5;
    // // if (n % 2)
    // // {
    // //     // find series first by even then add odd numbers
    // //     solve(n - 1, k, ans);
    // //     k = n;
    // //     ans.push_back(n);
    // //     return;
    // // }
    // ans = {2, 1, 3, 4, 5};
    // ll curr_k = 5;
    // for (ll i = 6; i <= n; i++)
    // {
    //     ans.push_back(i);
    //     if (i % 2 == 0)
    //     {
    //         curr_k = (curr_k | i);
    //     }
    //     else
    //     {
    //         curr_k = (curr_k & i);
    //     }
    // }
    // cout << curr_k << "\n";

    // // ll most_set_bit = 1LL << (63 - __builtin_clzll(n));
}

signed main()

{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> ans(n);
        ll k = 0;
        solve(n, ans);
        // print_array(ans);
    }
    return 0;
}
