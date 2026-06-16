#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int mx = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
                mx = max(mx, v[i] - v[i + 1]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                v[i + 1] += mx;
            }
        }
        int k = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                k = 0;
                break;
            }
        }
        if (k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
