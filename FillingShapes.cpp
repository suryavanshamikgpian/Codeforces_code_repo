#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if ((n % 2) == 1)
    {
        cout << 0;
    }
    else
    {
        cout << (long long)pow(2, n / 2);
    }
    return 0;
}
