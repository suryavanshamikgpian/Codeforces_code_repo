#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string S_tail(int n)
{
    string res = to_string(n);
    if (n <= 9)
        return res;
    int sum = 0, temp = n;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return res + S_tail(sum);
}

void solve()
{
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        cout << s << "\n";
        return;
    }

    vector<int> counts(10, 0);
    for (char c : s)
    {
        counts[c - '0']++;
    }

    for (int y = 1; y <= 9 * s.length(); y++)
    {
        string tail = S_tail(y);
        if (tail.length() >= s.length())
            continue;

        vector<int> rem = counts;
        bool ok = true;
        for (char c : tail)
            if (--rem[c - '0'] < 0)
                ok = false;

        if (ok)
        {
            long long sum_rem = 0;
            for (int i = 0; i < 10; i++)
                sum_rem += (long long)i * rem[i];

            if (sum_rem == y)
            {
                string x = "";
                for (int i = 1; i <= 9; i++)
                    if (rem[i] > 0)
                    {
                        x += (i + '0');
                        rem[i]--;
                        break;
                    }
                for (int i = 0; i <= 9; i++)
                    while (rem[i]-- > 0)
                        x += (i + '0');
                cout << x << tail << "\n";
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}