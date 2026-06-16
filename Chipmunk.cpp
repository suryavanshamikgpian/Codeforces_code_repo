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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int c = 0, x = 0;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            int b = a[i];
            vector<int> v1;
            while (b != 1)
            {
                if (b % 2)
                {
                    b++;
                    v1.push_back(1);
                }
                else
                {
                    b /= 2;
                    v1.push_back(2);
                }
                c++;
            }
            if (v1.size())
            {
                reverse(v1.begin(), v1.end());
                v.push_back(v1);
            }
            else
                x++;
        }

        if (x)
        {
            cout << min(c, c + x - n + x) << endl;
            continue;
        }
        int z = 0;
        for (int i = 0; i < v[0].size(); i++)
        {
            int y = 0;
            for (int j = 1; j < n; j++)
            {
                if (v[j][i] != v[0][i])
                {
                    y = 1;
                    break;
                }
            }
            if (y)
            {
                break;
            }
            z++;
        }
        cout << c - z * n << endl;
    }
}
