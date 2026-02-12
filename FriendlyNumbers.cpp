#include <bits/stdc++.h>
using namespace std;

int digitSum(long long n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;

        int count = 0;

        for (long long y = x + 1; y <= x + 100; y++)
        {
            if (y - digitSum(y) == x)
                count++;
        }

        cout << count << "\n";
    }
}
