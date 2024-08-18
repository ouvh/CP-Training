#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstring>
#include <set>
#include <cmath>
#include <fstream>
#define ll  long long
using namespace std;


struct CustomComparator {
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

ll comb(ll n,ll k,ll m){
    
    if(k == 0)return 1;
    if(n == k)return 1;
    if(k > n)return 0;

    ll result = 1;
    for (ll i = 1; i <= k; ++i) {
        result *= n - i + 1;
        result /= i;
        if (result > 1e18 || result < 0) return m + 1; 
    }
    return result;
    


}

int main(){
   
    int t;
    ll m;
    cin >> t;
    while(t--){

        set<pair<ll,ll>,CustomComparator> ans;
        cin >> m;
        ll bound = static_cast<ll>(log2(m))  + 2;

        for(ll i=1;i<bound;i++){
            
            
            
            ll min = i;

            // exponential growth to find a suitable upperbound
            ll max = i;
            while(comb(max,i,m) < m){
                max <<= 1;
            }


            // binary search
            while(max - min > 1){
                ll c = (min + max)/2;
                ll re = comb(c,i,m);
                if(re == m){ans.insert({c,i});ans.insert({c,c - i}); break;}
                else if(re < m)min = c;
                else max = c;
            }


            if(comb(min,i,m)==m){ans.insert({min,i});ans.insert({min,min - i});}
            if(comb(max,i,m)==m){ans.insert({max,i});ans.insert({max,max - i});}
            


        }
        cout << ans.size() << "\n";

        for (auto it = ans.begin(); it != ans.end(); ++it) {
            cout << "(" << (*it).first << "," << (*it).second << ")";
            if (next(it) != ans.end()) {
                cout << " "; 
            }
        }   

        cout << "\n";


        
    }

    return 0;
}
