#include <bits/stdc++.h>
using namespace std;
int findor(string s){
    int n_1=0;
    int n_2 = 0; 
    for(int i =0 ; i<s.size(); i++){
        if(s[i]=='0'){
            n_2++;
        }
        else{
            n_1++; 
        }
    }
    return abs(n_1-n_2);
}
int main(){
    int t ; 
    cin>>t; 
    while(t--){
        string s , tel; 
        cin>>s; 
        tel= s;
        string t; 
        string sample ; 
        for(int i =0 ;i<s.size() ;i++){
            if(s[i]=='0'){
                sample[i]='1';
            }
            else{
                sample[i]='0';
            }
        }
        int token =0; 
        for(int i =0 ;i<s.size() ;i++){
            int floced = tel.find(sample[i]); 
            if( floced !=-1){
                t[i]= sample[i]; 
                tel[i]='9';
                
            }
            else if(){

            }
        }
    }
    return 0; 
}
