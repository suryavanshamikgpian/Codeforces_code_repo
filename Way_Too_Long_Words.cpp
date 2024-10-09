#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n ; 
    cin>>n; 
    vector<string> storer;
    for(int i =0 ;i<n ;i++){
        string str ; 
        cin>>str;
        storer.push_back(str); 
    }
    for(int i =0 ;i<n ;i++){
        int t = storer[i].length(); 
        if(t>10){
            cout<<storer[i][0]<<t-2<<storer[i][t -1]<<endl;
        }
        else{
            cout<<storer[i]<<endl;
        }
    }
    return 0; 
}