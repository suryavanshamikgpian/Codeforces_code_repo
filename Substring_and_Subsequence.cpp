#include <bits/stdc++.h>
using namespace std; 
int main(){
    int t; 
    cin>>t; 
    while(t--){
        string a, b  ; 
        cin>>a; 
        cin>>b; 
        int l = a.size()+ b.size(); 
        for(int i =0 ;i<b.size() ;i++){
            if(a.find(b[i])!=-1 ){
                l= l-1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}