#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sumol(unordered_map<int, int> &mp, ll n) {
    ll ans = 0;
    for (auto &it : mp) {
        if (it.second > 1) {
            ans += it.first * (it.second * (it.second - 1)) / 2;
        }
    }
    return ans;
}
void solve() {
    ll n; 
    cin>>n ; 
    ll sum = 0; 
    ll ans =0; 
    unordered_map<int, int> mp;
    for(int i =0;i<n ;i++){
        int x;
        cin>>x;
        mp[x]++;
        sum += x;
    }
    cout<< sumol(mp,n)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
