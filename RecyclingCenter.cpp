#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ll contact(priority_queue<ll>&pq , ll c) {
//     if (pq.empty()) return 0;
//     ll coins = 0;
//     while (!pq.empty() && pq.top() > c) {
//         coins++;
//         // cout << pq.top() << " ";
//         pq.pop();
//     }
//     if (!pq.empty()) pq.pop(); // ensure pq not empty before pop
//     // cout << pq.top() << " ";
//     priority_queue<ll> lp; 
//     ll size = pq.size();
//     while(!pq.empty()) {
//         ll yel = pq.top();
//         pq.pop();
//         lp.push(2 * yel);
//     }
//     return coins + contact(lp, c);
// }

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> pq;
    ll x;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        pq.push_back(x);
    }
    ll j =0, x=1; 
    for(int i =n-1; i >= 0; i--) {
        if(x*pq[i]<=c){
            j++; 
            x=x*2; 
        }
    }
    cout << n-j;

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
