#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n , m;
    cin>>n>>m;
    long long i = n%m; 
    long long let = ceil((float)n/(float)m); 
    if(i!=0){
        cout<< (let *(let-1))/2 + (i*(i-1))/2<<" ";
    }
    else{
        cout<< m*(let *(let-1))/2<<" "; 
    }
    
    //for max finder ; 
    
    long long j = n-(m-1); //left in last group
    cout<<((j)*(j-1))/2 ; //max 
    

    return 0;
}