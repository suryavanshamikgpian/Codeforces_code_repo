#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t; 
    while(t--){
        int k ; 
        cin>>k; 
        priority_queue<long long > pq;
        for(int i =0 ;i<k ;i++){
            long long a ; 
            cin>>a;
            pq.push(a);
        }
        while(pq.size()>1){
            long long fighter1= pq.top();
            pq.pop();
            long long fighter2= pq.top();
            pq.pop();
            long long new_rating = fighter1-fighter2 ; 
            if(new_rating>0){
                pq.push(new_rating);
            }
        }
        if(pq.empty()){
            cout<<0<<endl;
        }
        else{
            cout<<pq.top()<<endl;
        }
    }
    return 0; 
}