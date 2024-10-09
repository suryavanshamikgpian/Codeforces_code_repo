#include <bits/stdc++.h>
using namespace std; 
int digo(long long n){
    int counter=0 ; 
    while(n){
        n=n/10;
        counter++;
    }
    return counter;
}
int main(){
    long long n ;
    cin>>n;
    int no_of_digit= digo(n);//2
    long long l =0;
    long long divisor = pow(10, no_of_digit - 1);
    //91730629
    for(int i =no_of_digit ; i>0 ;i=i-1){
        int k = n / divisor;
        n = n % divisor;
        divisor = divisor / 10;
        if(2*k > 9 &&  (i!=no_of_digit ||k!=9 )   ){
            l=l+(9-k);
        }
        else{
            l=l+k;
        }
        l=l*10;
    }
    cout<<l/10;
    return 0;
}