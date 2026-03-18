#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, k, p, m;
    cin >> n >> k >> p >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long win = a[p - 1];

    vector<long long> E1;
    for (int i = 0; i < p - 1; ++i)
    {
        E1.push_back(a[i]);
    }

    vector<long long> S;
    for (int i = 0; i < n; ++i)
    {
        if (i != p - 1)
        {
            S.push_back(a[i]);
        }
    }

    sort(E1.begin(), E1.end());
    sort(S.begin(), S.end());

    long long r1 = max(0LL, p - k);

    vector<long long> spec;
    for (int i = 0; i < r1; ++i)
    {
        spec.push_back(E1[i]);
    }
    long long low = 0, high = m / win, ans = 0;

    while (low <= high)
    {
        long long v = low + (high - low) / 2;

        if (v == 0)
        {
            ans = max(ans, 0LL);
            low = v + 1;
            continue;
        }

        long long cost = v * win;
        long long needed = r1 + (v - 1) * (n - k);

        int ptr_s = 0;
        int ptr_r = 0;
        long long rem_r = v - 1;

        bool ok = true;

        while (needed > 0)
        {
            long long val_s = (ptr_s < r1) ? spec[ptr_s] : 2e18;
            long long val_r = (ptr_r < S.size() && rem_r > 0) ? S[ptr_r] : 2e18;
            if (val_s == 2e18 && val_r == 2e18)
            {
                ok = false;
                break;
            }

            if (val_s <= val_r)
            {
                cost += val_s;
                ptr_s++;
                needed--;
            }
            else
            {
                long long take = min(needed, rem_r);
                cost += take * val_r;
                needed -= take;
                rem_r -= take;
                if (rem_r == 0)
                {
                    ptr_r++;
                    rem_r = v - 1;
                }
            }
            if (cost > m)
            {
                ok = false;
                break;
            }
        }

        if (ok && cost <= m)
        {
            ans = v;
            low = v + 1;
        }
        else
        {
            high = v - 1;
        }
    }

    cout << ans << "\n";
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