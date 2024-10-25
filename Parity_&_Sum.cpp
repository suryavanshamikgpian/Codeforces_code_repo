#include <bits/stdc++.h>
using namespace std; 
int main(){
    int t ; 
    cin>>t;
    while(t--){
        int n ; 
        cin>>n; 
        vector<int> even; 
        int no_of_even=0 ;
        int no_of_odd=0 ;
        vector<int> odd;
        for(int i =0 ;i<n ;i++ ){
            int res ; 
            cin>>res;
            if((res&1)==1){
                odd.push_back(res);
                no_of_odd++;
            }
            else{
                even.push_back(res);`
                no_of_even++;
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(),even.end()); 

         

    }
    return 0; 
}