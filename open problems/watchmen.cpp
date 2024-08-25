#include <iostream>
#include <unordered_map>
#include <map>
 
using namespace std;
 
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        std::size_t h1 = std::hash<T1>{}(pair.first);
        std::size_t h2 = std::hash<T2>{}(pair.second);
        return h1 ^ (h2 << 1);  // Combine the two hashes
    }
};
 
int main(){
    int n,x,y;
 
    unordered_map<int,long long> count_x;
    unordered_map<int,long long> count_y;
    unordered_map<pair<int,int>,long long,pair_hash> dup;
 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        dup[{x,y}]++;
 
        count_x[x]++;
        count_y[y]++;
 
    }
    long long answer = 0;
 
    for(auto pair:count_x){
        answer += pair.second * (pair.second - 1) / 2;
    }
    for(auto pair:count_y){
        answer += pair.second * (pair.second - 1) / 2;
    }
    for(auto pair:dup){
        answer -= pair.second * (pair.second - 1) / 2;
    }
    
 
    cout << answer;
    
    
    
    
    
    return 0;
}