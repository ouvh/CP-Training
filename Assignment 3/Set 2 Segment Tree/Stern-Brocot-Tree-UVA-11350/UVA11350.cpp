#include <iostream>
#include <cstdio>
#include <utility> 
#include <limits>
#include <vector>
#include <cmath>
#include <string>

#define ll long long



using namespace std;

struct Node{
    
    pair<pair<ll,ll>,pair<ll,ll>> boundary;
    pair<ll,ll> value;
    pair<bool,bool> children_existence;
    pair<Node*,Node*> children;

    Node(pair<pair<ll,ll>,pair<ll,ll>> bound,pair<ll,ll> value):boundary(bound),value(value),children_existence({false,false}){
    };

    Node():children_existence({false,false}){
    };

};

pair<ll,ll> DFS(Node &root,string s ,int position){
    if(position == s.size()){
        return root.value;
    }

    if(s[position]=='R'){
        if(root.children_existence.second)return DFS(*root.children.second,s,position+1);

        root.children.second = new Node({root.value,root.boundary.second},{root.value.first + root.boundary.second.first,root.value.second + root.boundary.second.second});
        root.children_existence.second = true;
        return DFS(*root.children.second,s,position+1);

    }else{

        if(root.children_existence.first)return DFS(*root.children.first,s,position+1);

        root.children_existence.first = true;
        root.children.first = new Node({root.boundary.first,root.value},{root.value.first + root.boundary.first.first,root.value.second + root.boundary.first.second});
        return DFS(*root.children.first,s,position+1);

    }

}





int main(){



    int t;
    string s;
    pair<ll,ll> result;
    Node root({{0,1},{1,0}},{1,1});
    cin >> t;



    while(t--){

        cin >> s;
        result = DFS(root,s,0);
        cout << result.first << "/" << result.second << "\n";
        
    }



    return 0;
}