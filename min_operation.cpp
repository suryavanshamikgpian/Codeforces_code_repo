#include <bits/stdc++.h>
using namespace std;
void caller(int n , int k, int& cal){
    if(n==0){
        return ;
    }
    double l = log((double)n) / (double)log(k); 
    int alpha = floor(l);
    cal++; 
    caller(n-pow(k,alpha) , k , cal);
}
int main(){
    int t; 
    cin>>t;
    while(t--){
        int n ,k; 
        cin>>n;
        cin>>k;
        if(n<k){
            cout<<n<<endl;
        }
        else{
            int cal =0; 
            caller(n,k,cal);
            cout<<cal<<endl; 
        }
    }
    return 0;
}