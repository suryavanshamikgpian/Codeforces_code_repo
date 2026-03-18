#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()

{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ll t;
    cin >> t;
    for (ll tc = 0; tc < t; tc++)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll odd = 0, even = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        sort(arr, arr + n);

        ll maxodd = 0, maxeven = 0;
        ll index = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
            {
                maxodd = arr[i];
                index = i;
            }
            else
            {
                maxeven = arr[i];
            }
        }
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0 && arr[i] <= maxodd)
            {
                maxodd = maxodd + arr[i];
            }
            else if (arr[i] % 2 == 0)
            {
                flag = 1;
                break;
            }
        }

        if (odd == 0 || even == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << even + flag << endl;
        }
    }
}