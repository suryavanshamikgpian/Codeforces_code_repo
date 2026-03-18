#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template <class T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  for (ll tc = 0; tc < t; tc++)
  {
    ll n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    ll arr[n][m];
    for (ll i = 0; i < n; i++)
    {
      for (ll j = 0; j < m; j++)
      {
        cin >> arr[i][j];
      }
    }
    vector<ll> rowsum(n);
    vector<ll> colsum(m);
    for (ll i = 0; i < n; i++)
    {
      for (ll j = 0; j < m; j++)
      {
        rowsum[i] += arr[i][j];
        colsum[j] += arr[i][j];
      }
    }
    ll r = 0;
    ll c = 0;
    for (ll i = 0; i < str.length(); i++)
    {
      if (str[i] == 'D')
      {
        arr[r][c] = -1 * rowsum[r];
        rowsum[r] += arr[r][c];
        colsum[c] += arr[r][c];
        r++;
      }
      else
      {
        arr[r][c] = -1 * colsum[c];
        rowsum[r] += arr[r][c];
        colsum[c] += arr[r][c];
        c++;
      }
    }
    arr[r][c] = -1 * rowsum[r];
    rowsum[r] += arr[r][c];
    colsum[c] += arr[r][c];
    r++;
    for (ll i = 0; i < n; i++)
    {
      for (ll j = 0; j < m; j++)
      {
        cout << arr[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}