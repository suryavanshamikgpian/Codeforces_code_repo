//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
bool checker(vector<bool> spec ){
    bool flago = true; 
    for(int i =0 ; i<n && flago ; i++){
        flago = flago && arr[i];
    }
    return flago; 
}


void convertor(int i,int j ,vector<bool>* spec , vector<int>* arr, int k ){
    if(arr[j]>i){
        return ;
    }
    else if(arr[j]<=i){
        spec[j] = ~(spec[j]); 
        arr[j]+= k ;
    }
}


int main(){
    int t ; 
    cin>>t;
    while(t--){
        int n ; 
        int k ; 
        cin>>n ; 
        cin>>k; 
        vector<int> arr; 
        for(int i =0 ; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<bool> spec(n,false) ; 
        for(int i = 0 ; ;i++){
            for(int j =0 ;j<n ;j++){
                convertor(i , j , &spec, &arr, k);
            }
            checker(spec, );
        }
    }
    return 0; 
}