/*#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> 
#include <fstream>
 
using namespace std;
 
int find(vector<int> &dsu,int i){
    if(dsu[i] == i)return i;
    int p = find(dsu,dsu[i]);
    dsu[i] = p;
    return p;
}
 
set<pair<int,int>> jjoin(set<pair<int,int>> &set1, set<pair<int,int>> &set2, vector<int> &dsu){
    set<pair<int,int>> result;
    for(auto pai:set2){
        if(find(dsu,pai.first) != find(dsu,pai.second))result.insert(pai);
    }
    for(auto pai:set1){
        if(find(dsu,pai.first) != find(dsu,pai.second))result.insert(pai);
    }
    return result;
 
}
 
 
int main(){
 
 
    int n,x,y;
    cin >> n;
  
 
    vector<set<pair<int,int>>> g1(n+1);
    vector<set<pair<int,int>>> g2(n+1);
 
    vector<int> dsu(n+1);
    vector<int> degree(n+1);
    vector<pair<pair<int,int>,pair<int,int>>> ans;
 
 
 
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g1[x].insert({min(x,y),max(x,y)});
        g1[y].insert({min(x,y),max(x,y)});
        degree[x]++;
        degree[y]++;
    }
     
 
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g2[x].insert({min(x,y),max(x,y)});
        g2[y].insert({min(x,y),max(x,y)});
 
    }
    
    for(int i=0;i<=n;i++){
       dsu[i] = i;
    }
 
    queue<int> Queue;
 
    for(int i=0;i<=n;i++){
       if(degree[i]==1)Queue.push(i);
    }
    
    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();
        degree[front]--;
        
        for(auto pai:g1[front]){
 
            int next = (pai.first == front ? pai.second:pai.first);
            g1[next].erase(pai);
            degree[next]--;
            if(degree[next] == 1)Queue.push(next);
            int leader = find(dsu,front);
 
 
 
 
            if(g2[leader].find(pai) != g2[leader].end()){
                dsu[leader] = next;
                g2[next] = jjoin(g2[next],g2[leader],dsu);
            }
            else{
 
                pair<int,int> result = *(g2[leader].begin());
                ans.push_back({pai,result});
                g2[leader].erase(result);
                int a = find(dsu,result.first);
                int b = find(dsu,result.second);
                int newleader = (a == leader ? b: a);
 
                dsu[leader] = newleader;
                g2[newleader] = jjoin(g2[leader],g2[newleader],dsu);
 
 
            
            }
 
        }
    }
    
   
 
 
    cout << ans.size() << "\n";
 
    for(auto i: ans){
        cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << endl;
    }
 
   
 
 
 
 
 
}*/
 
// second approach
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> 
#include <fstream>
 
using namespace std;
 
 
int find(vector<int> &dsu,int i){
    if(dsu[i] == i)return i;
    int p = find(dsu,dsu[i]);
    dsu[i] = p;
    return p;
}
 
void construct_parent(vector<int> &parent,int x,int previous,vector<vector<int>> &graph){
    parent[x] = previous;
    for(auto i:graph[x]){
        if(i != previous)construct_parent(parent,i,x,graph);
    }
 
}
 
void repair(vector<int> &dsu,vector<int> &parent1,vector<int> &parent2,int x,int previous,vector<vector<int>> &graph,vector<pair<pair<int,int>,pair<int,int>>> &ans){
    for(auto i:graph[x]){
        if(i != previous)repair(dsu,parent1,parent2,i,x,graph,ans);
    }
    if(previous != parent2[x] && x != parent2[previous]){
        ans.push_back({{x,previous},{find(dsu,x),parent2[find(dsu,x)]}});
    }
 
}
 
 
int main(){
 
 
    int n,x,y;
    cin >> n;
  
 
    vector<vector<int>> g1(n+1);
    vector<vector<int>> g2(n+1);
 
    vector<int> parent1(n+1);
    vector<int> parent2(n+1);
 
 
    vector<int> dsu(n+1);
    vector<pair<pair<int,int>,pair<int,int>>> ans;
 
 
 
 
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
     
 
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g2[x].push_back(y);
        g2[y].push_back(x);
 
    }
 
    construct_parent(parent1,1,1,g1);
    construct_parent(parent2,1,1,g2);
 
    dsu[1] = 1;
    for(int i=2;i<=n;i++){
        if(parent1[i] == parent2[i] || i == parent1[parent2[i]])dsu[i] = parent2[i];
        else dsu[i] = i;
    }
 
    repair(dsu,parent1,parent2,1,1,g1,ans);
 
 
    cout << ans.size() << "\n";
 
    for(auto i: ans){
        cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << endl;
    }
 
 
}