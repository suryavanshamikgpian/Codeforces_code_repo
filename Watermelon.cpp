#include <bits/stdc++.h>
using namespace std; 
int main(){
    int kg ; 
    cin>>kg;
    if(kg==2){
        cout<<"NO"<<endl;
    }
    else if(kg&1){
        cout<<"NO"<<endl; 
    }
    else{
        cout<<"Yes"<<endl; 
    }
    return 0; 
}