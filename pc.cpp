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
    ll open = 0, close = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '(')
            open++;
        else
            close++;
    }
    if (open != close)
    {
        cout << -1 << "\n";
        return;
    }
    stack<char> st;
    st.push(s[0]);
    ll k = 1;
    ll curr = (s[0] == '(') ? 1 : 2;

    unordered_set<int> st1;
    st1.insert(curr);
    vector<ll> ans;
    ans.push_back(curr);
    for (ll i = 1; i < n; i++)
    {
        if (st.empty())
        {
            curr = (s[i] == '(') ? 1 : 2;
            st1.insert(curr);
            ans.push_back(curr);
            st.push(s[i]);
        }
        else
        {
            ans.push_back(curr);
            if (s[i] == '(' && st.top() == ')' || s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    cout << st1.size() << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        if (st1.size() == 1)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << ans[i] << " ";
        }
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