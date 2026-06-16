#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1000005;
ll F[MAXN];
ll TCE[MAXN];
ll fact[MAXN];
ll invFact[MAXN];
long long binpow(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute()
{

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    F[0] = 1;
    TCE[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        if (i % 2 == 1)
        {
            F[i] = (F[i - 1] - invFact[i] + MOD) % MOD;
        }
        else
        {
            F[i] = (F[i - 1] + invFact[i]) % MOD;
        }
        TCE[i] = (TCE[i - 1] + F[i]) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << TCE[n] << "\n";
    }
    return 0;
}