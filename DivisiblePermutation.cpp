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
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            if (i == n && n % 2 == 1)
                cout << i << " ";
            else if (i % 2 == 1)
                cout << i + 1 << " ";
            else
                cout << i - 1 << " ";
        }
        cout << "\n";
    }
}
