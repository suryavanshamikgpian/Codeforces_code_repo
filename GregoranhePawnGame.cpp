#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1 >> s2;
        s1 += "0";
        s2 += "0";
        string en = "0", yo = "0";
        en += s1;
        yo += s2;

        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (yo[i] == '1')
            {
                if (en[i] == '0')
                {
                    cnt++;
                    en[i] = '2';
                }
                else if (en[i - 1] == '1')
                {
                    cnt++;
                    en[i - 1] = '2';
                }
                else if (en[i + 1] == '1')
                {
                    cnt++;
                    en[i + 1] = '2';
                }
                // cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}