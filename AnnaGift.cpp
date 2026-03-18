#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll total_digits = 0;
    vector<ll> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_digits += log10(a[i]) + 1; // Count digits in a[i]
        while (a[i] % 10 == 0)
        {
            a[i] /= 10;
            b[i]++;
        }
    }
    sort(b.begin(), b.end());
    for (int i = n - 1; i >= 0; i = i - 2)
    {
        total_digits -= b[i]; // Remove trailing zeros
    }
    if (m + 1 <= total_digits)
    {
        cout << "Sasha\n";
        return;
    }
    cout << "Anna\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    /*
    Time Complexity (TC): O(n log n) for sorting + O(sum log(a_i)) over digit processing + O(n)
    Space Complexity (SC): O(n)
    */
}
