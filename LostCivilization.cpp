#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
void printer_array(vector<ll> &a)
{
    cout << "Array: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

// void solver(int n, vector<ll> &a)
// {
//     for (ll i = n - 1; i >= 0; i--)
//     {
//         // printer_array(a);
//         if (i == 0)
//         {
//             break;
//         }
//         if (a[i] == -1)
//         {
//             continue;
//         }
//         ll j = i - 1;
//         while (j >= 0 && a[j] == -1)
//         {
//             j--;
//         }
//         // cout << "i: " << i << " j: " << j << "\n";
//         if (a[i] != -1 && (a[i] == a[j] + 1))
//         {
//             a[i] = -1;
//             i = n;
//         }
//     }
//     ll ans = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         if (a[i] != -1)
//         {
//             ans++;
//         }
//     }
//     cout << ans << "\n";
// }
void solver(int n, vector<ll> &a)
{
    stack<ll> st;

    for (ll i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() == a[i] + 1)
        {
            st.pop();
        }

        st.push(a[i]);
    }

    cout << st.size() << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tel;
    cin >> tel;
    while (tel--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solver(n, a);
    }
    return 0;
}
