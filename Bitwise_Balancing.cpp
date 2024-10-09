#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        long long b, c, d;
        cin >> b >> c >> d;  // Inputs for each test case

        // We check if there exists an 'a' such that (a | b) - (a & c) = d
        bool found = false;
        
        // Iterate over possible values of 'a'
        for (long long a = 0; a <= (1LL << 61); ++a) {
            if ((a | b) - (a & c) == d) {
                cout << a << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;  // If no 'a' found, output -1
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);  // Fast input-output
    cin.tie(0);
    solve();
    return 0;
}
