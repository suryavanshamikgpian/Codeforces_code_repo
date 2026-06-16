#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> v;
    for (ll i = 0; i < 13; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << endl;
    string s;
    for (ll i = 0; i < 13; i++)
    {
        s += v[i].back();
    }
    cout << s << endl;

    return 0;
}
