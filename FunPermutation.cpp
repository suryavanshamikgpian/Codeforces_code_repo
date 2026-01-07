#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> ans_array;
        for (int i = 0; i < n; i++)
        {
            ans_array.push_back(n - arr[i] + 1);
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans_array[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
