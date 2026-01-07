#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_bad(vector<int>& q) {
    if (q.size() < 5) return false;
    for (int i = 0; i + 4 < q.size(); ++i) {
        if (q[i] < q[i+1] && q[i+1] < q[i+2] && q[i+2] < q[i+3] && q[i+3] < q[i+4])
            return true;
        if (q[i] > q[i+1] && q[i+1] > q[i+2] && q[i+2] > q[i+3] && q[i+3] > q[i+4])
            return true;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n; 
    deque<int> dq(n);
    for (int i = 0; i < n; ++i) cin >> dq[i];
    vector<int> q; 
    string ans;
    int index =0; 
    while(!dq.empty()){
        int left = dq.front();
        int right = dq.back();
        bool choose_left = true;
        q.push_back(left);
        if(!is_bad(q)) {
            dq.pop_front();
            ans += 'L';
            continue;
        }
        q.pop_back();
        q.push_back(right);
        if(!is_bad(q)) {
            dq.pop_back();
            ans += 'R';
            continue;
        }
        q.pop_back();
        // abb ayega ki dono hi bad hain
        int size = ans.size(); 
        if(ans[size-1] == 'L') {
            ans.erase(ans.end() - 1);
            auto it = q.end() - 1;
            dq.push_front(*it);
            q.pop_back();
            ans += 'R';
            dq.pop_back();
        }
        else {
            ans.erase(ans.end() - 1);
            auto it = q.end() - 1;
            dq.push_back(*it);
            q.pop_back();
            ans += 'L';
            dq.pop_front(); 
        }
    }
    cout << ans << '\n';

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
