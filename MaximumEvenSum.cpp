#include <bits/stdc++.h>
using namespace std;
using u128 = __uint128_t;
using u64 = unsigned long long;

// ---------- Miller-Rabin primality test ----------
u64 modmul(u64 a, u64 b, u64 m)
{
    return (u128)a * b % m;
}
u64 modpow(u64 a, u64 d, u64 m)
{
    u64 r = 1;
    while (d)
    {
        if (d & 1)
            r = modmul(r, a, m);
        a = modmul(a, a, m);
        d >>= 1;
    }
    return r;
}
bool isPrime(u64 n)
{
    if (n < 2)
        return false;
    for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n % p == 0)
            return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    {
        if (a % n == 0)
            continue;
        u64 x = modpow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (u64 r = 1; r < s; r++)
        {
            x = modmul(x, x, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

// ---------- Pollard's Rho factorization ----------
u64 f_rho(u64 x, u64 c, u64 mod)
{
    return (modmul(x, x, mod) + c) % mod;
}
u64 rho(u64 n)
{
    if ((n & 1) == 0)
        return 2;
    static std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true)
    {
        u64 x = uniform_int_distribution<u64>(2, n - 2)(rng);
        u64 y = x;
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 d = 1;
        while (d == 1)
        {
            x = f_rho(x, c, n);
            y = f_rho(f_rho(y, c, n), c, n);
            d = gcd<u64>(x > y ? x - y : y - x, n);
        }
        if (d != n)
            return d;
    }
}
void factor(u64 n, vector<u64> &fac)
{
    if (n == 1)
        return;
    if (isPrime(n))
    {
        fac.push_back(n);
        return;
    }
    u64 d = rho(n);
    factor(d, fac);
    factor(n / d, fac);
}

// ---------- Main solve ----------
void solve()
{
    long long a, b;
    cin >> a >> b;

    vector<u64> primes;
    factor(b, primes);

    // count prime powers
    unordered_map<u64, int> cnt;
    for (auto p : primes)
        cnt[p]++;

    // generate divisors
    vector<u64> divisors = {1};
    for (auto [p, e] : cnt)
    {
        vector<u64> newdiv;
        u64 mul = 1;
        for (int i = 0; i < e; i++)
        {
            mul *= p;
            for (auto d : divisors)
                newdiv.push_back(d * mul);
        }
        divisors.insert(divisors.end(), newdiv.begin(), newdiv.end());
    }

    long long ans = -1;
    for (auto k : divisors)
    {
        long long sum = a * (long long)k + b / (long long)k;
        if (sum % 2 == 0)
            ans = max(ans, sum);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
