#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n ; 
    cin>>n ; 
    __int128 n128 = n;
    __int128 even_sumol, odd_sumol;
    if((n+1)&1){
        // odd
        even_sumol = n128*(n128+2)/4; 
        odd_sumol = n128*n128/4;
        cout<< even_sumol- odd_sumol;
        return 0;
    }
    else{
        odd_sumol = (n128+1)*(n128+1)/4;
        even_sumol = (n128-1)*(n128+1)/4; 
        cout<< even_sumol- odd_sumol;
        return 0;
    }
    return 0; 
}