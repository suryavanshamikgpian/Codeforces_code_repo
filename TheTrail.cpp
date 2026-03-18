#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solver(int n, int m, vector<ll> &rowsum, vector<ll> &colsum, ll target, string &s, vector<vector<ll>> &a)
{
    ll i = 0, j = 0;
    for (ll k = 0; k < s.length(); k++)
    {
        char c = s[k];
        if (c == 'D')
        {
            ll new_cell = -1 * rowsum[i];
            a[i][j] = new_cell;
            rowsum[i] = 0;
            colsum[j] = colsum[j] + new_cell;
            i++;
        }
        else
        {
            ll new_cell = -1 * colsum[j];
            a[i][j] = new_cell;
            colsum[j] = 0;
            rowsum[i] = rowsum[i] + new_cell;
            j++;
        }
    }
    ll r = i;
    ll c = j;
    a[r][c] = -1 * rowsum[r];
    rowsum[r] += a[r][c];
    colsum[c] += a[r][c];
    r++;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<ll> rowsum(n, 0);
        vector<ll> colsum(m, 0);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                rowsum[i] += a[i][j];
                colsum[j] += a[i][j];
            }
        }
        ll target = 0;
        solver(n, m, rowsum, colsum, target, s, a);
    }
    return 0;
}
