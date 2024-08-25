
#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    int q,n;
    string s,t;
    cin >> q;
    
    while(q--){
        cin >> n;
        cin >> s;
        cin >> t;
        int p_s=-1,p_t=-1;
        for(int i=0;i<n;i++){
            if (s[i]=='1') {p_s = i;break;}
        }
        for(int i=0;i<n;i++){
            if (t[i]=='1') {p_t = i;break;}
        }
        if(p_t < p_s)cout << "No" << "\n";
        else cout << "Yes" << "\n";
        
    }
    
    
    
    
    return 0;
}