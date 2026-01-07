#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long minMoves(vector<int> &balance)
{
    bool no_neg = false;
    ll n = balance.size();
    ll b = 0;
    ll ind = 0;
    for (ll i = 0; i < n; i++)
    {
        if (balance[i] < 0)
        {
            ind = i;
            no_neg = true;
        }

        b += balance[i];
    }
    if (!no_neg)
    {
        return 0;
    }
    if (b < 0)
    {
        return -1;
    }
    ll score = 0;
    ll l = ((ind - 1) + 7) % 7;
    ll r = ((ind + 1) + 7) % 7;
    ll gj = 0;
    while (balance[ind] < 0)
    {
        while (balance[ind] < 0 && balance[r] > 0)
        {
            balance[ind]++;
            balance[r]--;
            score++;
        }
        gj++;
        r = ((ind + 1 + gj) + n) % n;

        while (balance[ind] < 0 && balance[l] > 0)
        {
            balance[ind]++;
            balance[l]--;
            score++;
        }
        l = ((ind - 1 - gj) + n) % n;
    }
    return score;
}
void solve()
{
    ll n;
    cin >> n;
    vector<int> balance(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> balance[i];
    }
    cout << minMoves(balance) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}
