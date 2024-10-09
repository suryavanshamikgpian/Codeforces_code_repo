#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t;
    while(t--){
        string s ;
        cin>>s;
        int zero=0;
        int one = 0;
        for(int i =0 ; i<s.size(); i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        int i =0;
        for(i =0 ; i<s.size(); i++){
            if(s[i]=='0'){
                if(one){
                    one--; 
                }
                else{
                    break;
                }
            }
            else{
                if(zero){
                    zero--;
                }
                else{
                    break;
                }
            }
        }
        cout<<s.size()-i<<endl;
    }
    return 0; 
}