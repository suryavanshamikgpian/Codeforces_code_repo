#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    st.push(s[0]);
    for (ll i = 1; i < s.size(); i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << (st.size() == 0 ? "YES" : "NO") << "\n";
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}