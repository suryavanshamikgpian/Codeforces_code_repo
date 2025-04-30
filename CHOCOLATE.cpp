#include<bits/stdc++.h>
using namespace std;
int N = 33, M = 33, K = 55;
int dp[33][33][55];

void solve(){
    for(int i =1 ;i<N ;i++){
        for(int j =1 ;j<M ;j++){
            for(int l =0 ;l<K ;l++){
                if((i*j)<l ){
                    dp[i][j][l] = INT_MAX;
                    continue;
                }
                if(l==0 || (i*j)==l){
                    dp[i][j][l] = 0;
                    continue;
                }
                dp[i][j][l] = INT_MAX;
                for(int i1 = 1 ;i1<i ; i1++){
                    for(int l1 = 0 ; l1<=l; l1++){
                        int i2 = i-i1, l2= l-l1;
                        if (l1 <= i1 * j && l2 <= i2 * j && dp[i1][j][l1] != INT_MAX && dp[i2][j][l2] != INT_MAX)
                            dp[i][j][l] = min(dp[i][j][l], dp[i1][j][l1] + dp[i2][j][l2] + j * j);
                    }
                }
                for(int j1 = 1 ; j1<j ; j1++){
                    for(int l1 =0 ; l1 <=l ; l1++){
                        int j2 = j-j1 , l2= l-l1; 
                        if (l1 <= i * j1 && l2 <= i * j2 && dp[i][j1][l1] != INT_MAX && dp[i][j2][l2] != INT_MAX)
                            dp[i][j][l] = min(dp[i][j][l], dp[i][j1][l1] + dp[i][j2][l2] + i * i);

                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin>>t;
    solve();
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<"\n";
    }
}