#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1)
    {
        cout << -1 << "\n";
        return;
    }
    stack<char> st;
    st.push(s[0]);
    ll k = 1;
    ll curr = 1;
    vector<ll> ans(n);
    ans.push_back(curr);
    char prev = s[0];
    vector<char> v;
    vector<int> idx;

    cout << k << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}

/*
66
)(()(((()))()()(())))((()))))(()(()(())))()()(()(())((()))(())((()
2
2
22111111111111111111111111222222222222222222211222222222222222222211
10
1122222222222222222222223344444555555555555556677777777777777777889999999999910 10
 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 4 4 4 4 5 5 5 5 5 5 5 5 5 5 6 6 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 8 8 9 9 9 9 9 9 9 9 10 10
*/

// for (ll i = 1; i < n; i++)
// {
//     if (st.empty())
//     {
//         if (prev == s[i])
//         {
//             k++;
//             curr++;
//         }
//         ans.push_back(curr);
//         st.push(s[i]);
//     }
//     else
//     {
//         prev = s[i];
//         ans.push_back(curr);
//         if (s[i] == '(' && st.top() == ')' || s[i] == ')' && st.top() == '(')
//         {
//             st.pop();
//         }
//         else
//         {
//             st.push(s[i]);
//         }
//     }
// }