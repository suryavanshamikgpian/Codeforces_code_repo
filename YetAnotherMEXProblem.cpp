#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        unordered_set<int> s(a.begin(), a.end());

        int mex = 0;
        while (s.count(mex))
            mex++;

        cout << min(mex, k - 1) << "\n";
    }
}
