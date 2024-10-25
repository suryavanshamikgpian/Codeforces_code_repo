#include <bits/stdc++.h>
using namespace std; 
int sumol(int n){
    int lol =0 ;
    while(n){
        lol+=n%10;
        n/=10;
    }
    return lol;
}

int main(){
    int t ;
    cin>>t; 
    while(t--){
        int n ; 
        cin>>n ; 
        cout<<sumol(n)<<endl;
    }
    return 0; 
}