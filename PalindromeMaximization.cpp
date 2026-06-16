#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> pairs_needed(n);
    vector<int> freq(26, 0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        pairs_needed[i] = s.length() / 2;
        for (char c : s)
        {
            freq[c - 'a']++;
        }
    }

    int total_pairs = 0;
    for (int count : freq)
    {
        total_pairs += count / 2;
    }

    sort(pairs_needed.begin(), pairs_needed.end());

    int palindromes_formed = 0;
    for (int needed : pairs_needed)
    {
        if (total_pairs >= needed)
        {
            total_pairs -= needed;
            palindromes_formed++;
        }
    }

    cout << palindromes_formed << "\n";
    return 0;
}