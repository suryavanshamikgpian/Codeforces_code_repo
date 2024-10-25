//{ Driver Code Starts
#include <iostream>
#include <string>
using namespace std;
int counter(string s , char A){
    int count=0 ; 
    for(int i =0 ; i<s.length() ;i++){
        if(s[i]==A){
            count++;
        }
    }
    return count;
}
int main(){
    int t ; 
    cin>>t ; 

    while(t--){
        int n ; 
        cin>>n;
        string str; 
        cin>>str ; 
        int a = counter(str, 'A');
        int b = counter(str, 'B');
        int c = counter(str, 'C');
        int d = counter(str, 'D');
        int les = counter(str, '?');
        int marks = 0;
        if(a<=n){
            marks += a ;
        }
        else{
            marks+= n ; 
        }
        if(b<=n){
            marks += b ;
        }
        else{
            marks+= n ; 
        }
        if(c<=n){
            marks += c ;
        }
        else{
            marks+= n ; 
        }
        if(d<=n){
            marks += d ;
        }
        else{
            marks+= n ; 
        }
        cout<<marks<<endl; 
    }
    return 0; 
}

