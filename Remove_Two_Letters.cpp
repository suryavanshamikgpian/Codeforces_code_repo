#include <bits/stdc++.h>
using namespace std; 
string slip(string s, int i, int n){
    string lester ; 
    if(i!=-1){
        lester.append(s,0,i-1);
        lester.append(s, i+2,n-1 ); 
    }
    else{
        lester.append(s,2,n-1);
    }
    return lester; 
}
int main(){
    int t ; 
    cin>>t ; 
    
    while(t--){
        int n ; 
        cin>>n ; 
        string str;
        cin>>str; 
        stack<string> setlo; 
        for(int i =0 ;i<=n-2 ;i++){
            string les= slip(str,i,n);
            cout<<setlo.top()<<endl ; 
            if(setlo.empty() || setlo.top()!=les ){
                setlo.push(les);
            }
            cout<<les<<endl;
            
        }
        cout<<setlo.size(); 
    }
    return 0; 
}