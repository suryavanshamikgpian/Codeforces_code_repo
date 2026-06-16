#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    unordered_map<ll, ll> freq;
    vector<ll> arr(n + 1);
    arr[0] = 0;
    bool flag = true;
    srand(time(0));
    for (ll i = 1; i <= n; i++)
    {
        while (flag)
        {
            int x = (rand() % (2 * n)) + 1;
            if (freq[x] == 0 && freq[x + arr[i - 1]] == 0)
            {
                arr[i] = x;
                freq[x]++;
                freq[x + arr[i - 1]]++;
                flag = false;
            }
        }
        flag = true;
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}