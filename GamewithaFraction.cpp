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
        long long p, q;
        cin >> p >> q;
        __int128 P = p, Q = q;

        if (Q > P && 2 * Q <= 3 * P)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}
