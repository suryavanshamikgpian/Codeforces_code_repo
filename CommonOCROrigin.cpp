#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

void solve()
{
    string S, T;
    cin >> S >> T;

    int i = 0, j = 0;
    long long remS = 0, remT = 0;

    while (i < S.length() || j < T.length() || remS > 0 || remT > 0)
    {
        if (remS > 0 && remT > 0)
        {
            long long m = min(remS, remT);
            remS -= m;
            remT -= m;
            continue;
        }
        if (remS == 0 && i < S.length() && isdigit(S[i]))
        {
            long long val = 0;
            while (i < S.length() && isdigit(S[i]))
            {
                val = val * 10 + (S[i] - '0');
                i++;
            }
            remS += val;
            continue;
        }
        if (remT == 0 && j < T.length() && isdigit(T[j]))
        {
            long long val = 0;
            while (j < T.length() && isdigit(T[j]))
            {
                val = val * 10 + (T[j] - '0');
                j++;
            }
            remT += val;
            continue;
        }

        if (remS > 0)
        {
            if (j < T.length() && isalpha(T[j]))
            {
                remS--;
                j++;
                continue;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        if (remT > 0)
        {
            if (i < S.length() && isalpha(S[i]))
            {
                remT--;
                i++;
                continue;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }

        if (i < S.length() && j < T.length() && isalpha(S[i]) && isalpha(T[j]))
        {
            if (S[i] == T[j])
            {
                i++;
                j++;
                continue;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }

        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}