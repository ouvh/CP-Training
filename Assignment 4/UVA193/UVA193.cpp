#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

bool isvalidblack(set<int> &a,set<int> &b){
    set<int> temp;
    set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          inserter(temp, temp.begin()));
    return temp.empty();

}




void solve(vector<set<int>> &g,set<int> &current, set<int> &maxblack,int node){
    if(node >= g.size()){
        if (current.size() > maxblack.size())maxblack = current;
    }
    else{

        // white
        solve(g,current,maxblack,node+1);

        //black
        if (isvalidblack(current,g[node])){
            current.insert(node);
            solve(g,current,maxblack,node+1);
            current.erase(node);

        }
        

    }

}


int main(){
    
    int t,n,m,temp1,temp2;
    cin >> t;

    while(t--){
        cin >> n;
        cin >> m;
        vector<set<int>> g(n+1);
        set<int> maxblack;
        set<int> currentblack;
        



        for(int i=0;i<m;i++){
            cin >> temp1 >> temp2;
            g[temp1].insert(temp2);
            g[temp2].insert(temp1);

        }

        solve(g,currentblack,maxblack,1);
        cout << maxblack.size() << "\n";

        
        for (auto it = maxblack.begin(); it != maxblack.end(); ++it) {
            cout << *it;
            if (std::next(it) != maxblack.end()) {
                cout << " "; 
            }
        }   

        cout << "\n";



    }


    return 0;
}