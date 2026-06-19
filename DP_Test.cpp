#include <bits/stdc++.h>
using namespace std;
const int NEG = -1e9;
int solve_dp(int n, int m, vector<int> a) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, NEG));
    dp[0][0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int k=0; k<=i; ++k) {
            // delete i
            if(k > 0) dp[i][k] = max(dp[i][k], dp[i-1][k-1]);
            // keep i
            dp[i][k] = max(dp[i][k], dp[i-1][k]);
            if(i - k == a[i]) {
                dp[i][k] = max(dp[i][k], dp[i-1][k] + 1);
            }
        }
    }
    return dp[n][n - m]; // total deletions is n - m
}
int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1);
        for(int i=1; i<=n; ++i) cin >> a[i];
        cout << n - solve_dp(n, m, a) << endl;
    }
}
