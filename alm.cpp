#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void cal(ll n, string s, ll cX, ll cV, ll cI)
{
    long long ans = 0;

    // Count fixed I's that are followed by '?' (bonus pairing opportunities)
    int bonusSlots = 0;

    // Calculate base value from fixed characters
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'X')
        {
            ans += 10;
        }
        else if (s[i] == 'V')
        {
            ans += 5;
        }
        else if (s[i] == 'I')
        {
            // Check what follows
            if (i + 1 < n && (s[i + 1] == 'X' || s[i + 1] == 'V'))
            {
                ans -= 1; // I before X or V
            }
            else if (i + 1 < n && s[i + 1] == '?')
            {
                ans += 1; // Temporarily count as +1, may become -1
                bonusSlots++;
            }
            else
            {
                ans += 1; // I before I, another ?, or end
            }
        }
    }

    // For '?' positions: we have cX X's, cV V's, cI I's to place
    // Base value: 10*cX + 5*cV + cI (treating all I as +1)
    ans += 10LL * cX + 5LL * cV + cI;

    // Pairing optimization: each IX or IV pair saves 2
    int pairs = min(cI, cX + cV);
    ans -= 2LL * pairs;

    // Bonus: if we have leftover X or V (after pairing with our I's),
    // we can use them to convert fixed I's before '?' to -1
    int leftoverXV = (cX + cV) - pairs;
    int bonusUsed = min(leftoverXV, bonusSlots);
    ans -= 2LL * bonusUsed;

    cout << ans << '\n';
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)
    {
        ll nx, nv, ni;
        cin >> nx >> nv >> ni;
        cal(n, s, nx, nv, ni);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}