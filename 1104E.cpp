#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
            cin >> b[i];

        vector<ll> cyc(n + 1, -1), pos(n + 1, 0);
        vector<vector<ll>> elems;
        vector<ll> len;

        for (ll i = 1; i <= n; i++)
        {
            if (cyc[i] != -1)
                continue;
            vector<ll> tmp;
            for (ll x = i;;)
            {
                tmp.push_back(x);
                x = a[x];
                if (x == i)
                    break;
            }
            ll L = tmp.size(), mi = 0;
            for (ll k = 1; k < L; k++)
                if (tmp[k] < tmp[mi])
                    mi = k;
            vector<ll> rot(L);
            for (ll k = 0; k < L; k++)
                rot[k] = tmp[(mi + k) % L];
            ll id = elems.size();
            elems.push_back(rot);
            len.push_back(L);
            for (ll k = 0; k < L; k++)
                cyc[rot[k]] = id, pos[rot[k]] = k;
        }

        ll C = elems.size();
        vector<ll> tarCyc(C, -1), sh(C, -1), taken(C, 0);
        bool ok = true;

        for (ll i = 1; i <= n && ok; i++)
        {
            if (b[i] == -1)
                continue;
            ll v = b[i], X = cyc[i], Y = cyc[v], L = len[X];
            if (len[X] != len[Y])
            {
                ok = false;
                break;
            }
            ll s = ((pos[v] - pos[i]) % L + L) % L;
            if (tarCyc[X] == -1)
                tarCyc[X] = Y, sh[X] = s;
            else if (tarCyc[X] != Y || sh[X] != s)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            for (ll X = 0; X < C && ok; X++)
            {
                if (tarCyc[X] == -1)
                    continue;
                if (taken[tarCyc[X]])
                {
                    ok = false;
                    break;
                }
                taken[tarCyc[X]] = 1;
            }

        if (ok)
        {
            for (ll X = 0; X < C; X++)
            {
                if (tarCyc[X] == -1)
                    continue;
                ll Y = tarCyc[X], s = sh[X], L = len[X];
                for (ll k = 0; k < L; k++)
                    b[elems[X][k]] = elems[Y][(k + s) % L];
            }
            vector<set<ll>> avail(n + 1);
            for (ll c = 0; c < C; c++)
                if (!taken[c])
                    for (ll e : elems[c])
                        avail[len[c]].insert(e);
            for (ll i = 1; i <= n; i++)
            {
                if (b[i] != -1)
                    continue;
                ll X = cyc[i], L = len[X], w = *avail[L].begin(), Y = cyc[w];
                ll s = ((pos[w] - pos[i]) % L + L) % L;
                for (ll k = 0; k < L; k++)
                    b[elems[X][k]] = elems[Y][(k + s) % L];
                for (ll e : elems[Y])
                    avail[L].erase(e);
            }
        }

        if (!ok)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (ll i = 1; i <= n; i++)
                cout << b[i] << " ";
            cout << "\n";
        }
    }
}