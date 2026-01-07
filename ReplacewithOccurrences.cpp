#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        bool valid = true;
        for (auto &p : freq)
        {
            if (p.second % p.first != 0)
            {
                cout << -1 << "\n";
                valid = false;
                break;
            }
        }

        if (!valid)
            continue;

        unordered_map<int, int> val, countMap;
        vector<int> finalArr;
        int next_id = 1;

        for (int x : arr)
        {
            countMap[x]++;
            if (val[x] == 0)
            {
                val[x] = next_id++;
            }
            finalArr.push_back(val[x]);
            if (countMap[x] % x == 0)
            {
                val[x] = next_id++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << finalArr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
