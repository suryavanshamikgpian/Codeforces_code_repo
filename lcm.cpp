#include <bits/stdc++.h>
using namespace std;
int lcmer(int a , int b){
    int hcf ; 
        while(a!=0 && b!=0){
            if(a<=b){
                b= b%a;
            }
            else if(a>b){
                a = a%b;
            }
        }
        if(a!=0){
            hcf=a;
        }
        else{
            hcf=b; 
        }
    return (a*b)/hcf;
}

int main(){
    int t; 
    cin>>t; 
    while(t--){
        int l , r; 
        cin>>l>>r; 
        int l_dash =l ; 
        int r_dash= r; 




    }

    return 0; 
}
//8 12 
//8 4
//0 4
/*
13 37
13 11
2 11
2 1
0 1


*/