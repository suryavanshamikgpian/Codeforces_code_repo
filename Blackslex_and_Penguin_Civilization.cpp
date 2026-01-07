#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(1 << n, 1);
    vector<ll> res;
    a[(1 << n) - 1] = 0;
    res.push_back((1 << n) - 1);
    ll init = (1 << n) - 1;
    ll i = n;
    cout << init << " ";
    while (res.size() < (1 << n))
    {
        i = i - 1;
        ll expected = (1 << i) - 1;
        for (ll i = 0; i < (1 << n); i++)
        {
            if ((a[i] == 1) && (init & i) == expected)
            {
                a[i] = 0;
                cout << i << " ";
                res.push_back(i);
            }
        }
        init = expected;
    }
    cout << "\n";
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

// // {0,1,2,3}
// 0, 1, 01, 11 2 ^ n - 1,

//     n = 3,
//     {0, 1, 2, 3, 4, 5, 6, 7}
// // answer give :- 7 3 1 5 0 2 4 6
// {
//     7, 3, 1, 5, 0,
// }
// {2 ^ 3 - 1, 2 ^ 2 - 1, 2 ^ 1 - 1, 2 ^ 3 - 3, 2 ^ 0 - 1, 2 ^ 1 - 2, 2 ^ 2 - 4, 2 ^ 3 - 0} 001 -
//     4 101 - 5 111 - 7 011 - 3 010 - 2 110 - 6 100 - 1 000 - 0

//     // answer :- 15 7 3 11 1 5 9 13 0 2 4 6 8 10 12 14 n =

//     1111,
//     15 0111, 7 0011, 3 1011, 11 0001, 1 0101, 5 1001, 9 1101, 13
