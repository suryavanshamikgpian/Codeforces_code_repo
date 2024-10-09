#include <iostream> 
#include <string>
using namespace std; 
int main(){
    string burger;
    int nb,ns,nc;
    int pb,ps,pc; 
    int r; 
    getline(cin, burger);
    cin>>nb >> ns >>nc;  
    cin>> pb>> ps >>pc; 
    cin>>r; 
    // r= total money he has ; 
    int no_of_b_in_1=0; 
    int no_of_s_in_1=0; 
    int no_of_c_in_1=0;
    for(int i =0 ; i<burger.size();i++){
        if(burger[i]=='B'){
            no_of_b_in_1++;
        }
        else if(burger[i]=='S'){
            no_of_s_in_1++;
        }
        else if(burger[i]=='C'){
            no_of_c_in_1++;
        }
    }

    while(nb>=0 && ns>=0 && nc>=0){
        nb-= no_of_b_in_1;
        ns-= no_of_s_in_1; 
        nc-=no_of_c_in_1 ;
    }





    return 0; 
}