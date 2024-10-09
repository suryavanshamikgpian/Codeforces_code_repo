#include<bits/stdc++.h>
using namespace std;
int yes =0 ;

int main(){
    int t ; 
    cin>>t; 
    while(t--){
        int* lest = &yes; 
        *lest =0 ; 
        int n ;
        cin>>n ; 
        int x,y;
        cin>>x; 
        cin>>y; 
        if(x>y){
            cout<< (n/y) + (n%y!=0);
        }
        else if(y>x){
            cout<<((n/x) + (n%x!=0));

        }
        else if(x==y){
            cout<<((n/x) + (n%x!=0));
        }
        cout<<endl;
    }
    return 0; 
}