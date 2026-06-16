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
        long long n;
        cin >> n;

        long long r = n % 12;

        if (r != 10)
        {
            cout << r << " " << n - r << "\n";
        }
        else
        {
            if (n == 10)
                cout << -1 << "\n";
            else
                cout << 22 << " " << n - 22 << "\n";
        }
    }
}