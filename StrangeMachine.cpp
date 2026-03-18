#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    // Check if there is at least one 'B' machine to avoid TLE on "all A" cases
    bool hasB = false;
    for (char c : s)
    {
        if (c == 'B')
        {
            hasB = true;
            break;
        }
    }

    while (q--)
    {
        ll a;
        cin >> a;

        if (!hasB)
        {
            // Optimization: if all machines are 'A', it takes exactly 'a' seconds
            cout << a << "\n";
        }
        else
        {
            // Simulation: guaranteed to be fast (max ~600 steps) because 'B' exists
            ll steps = 0;
            int current_machine = 0; // 0-indexed (Machine 1 is s[0])

            while (a > 0)
            {
                if (s[current_machine] == 'A')
                {
                    a -= 1;
                }
                else
                {
                    a /= 2; // Floor of half is equivalent to integer division by 2
                }
                steps++;
                current_machine = (current_machine + 1) % n;
            }
            cout << steps << "\n";
        }
    }
}
signed main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}