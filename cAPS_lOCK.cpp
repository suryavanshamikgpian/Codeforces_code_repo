#include <bits/stdc++.h>
using namespace std; 
int main(){
    string str; 
    cin>>str; 
    int c=0; 
    for(int i =1 ; i<str.size(); i++){
        if(str[i]>='A' && str[i]<= 'Z'){
            c++;
        }
    }
    if(c== str.size()-1){
        for(int i =0 ;i<str.size() ;i++){
            if(str[i]>='A' && str[i]<= 'Z'){
                str[i]= str[i]+32; 
            }
            else{
                str[i]= str[i]-32; 
            }
        }
    }
    cout<<str<<endl; 
    return 0; 
}