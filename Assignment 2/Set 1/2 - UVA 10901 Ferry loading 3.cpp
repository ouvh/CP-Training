#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int tt;cin>>tt;
    while(tt--){
        int n,t,m,curr=0;cin>>n>>t>>m;
        deque<int> right,left;
        vi ans_left,ans_right;
        vector<string> order(m);
        for(int i=0;i<m;i++){
            int val;
            cin>>val>>order[i];
            if(order[i]=="left")left.push_back(val);
            else right.push_back(val);
        }
        //we insert from back and remove from front
        string state="left";
        while(!right.empty() || !left.empty()){
            //cout<<"here is state and time "<<state<<" "<<curr<<endl;
            if(state=="left" && !left.empty() && curr>=left[0]){
                for(int i=0;i<n;i++){
                    if(!left.empty() && curr>=left[0]){
                        left.pop_front();
                        ans_left.push_back(curr+t);
                    }
                    else break;
                }
                state="right";
                curr+=t;
            }
            else if(state=="right" && !right.empty() && curr>=right[0]){
                for(int i=0;i<n;i++){
                    if(!right.empty() && curr>=right[0]){
                        right.pop_front();
                        ans_right.push_back(curr+t);
                    }
                    else break;
                }
                state="left";
                curr+=t;
            }
            else if(state=="right"){
//we are on the station right but no one is there
                if(!left.empty() && curr >= left[0]){//go to left
                    state="left";
                    curr+=t;
                }
                else{
                    int r=1e9,l=1e9;
                    if(!right.empty())r=right[0];
                    if(!left.empty())l=left[0];
                    if(min(l,r)!=1e9)curr=min(l,r);
                }
            }
            else if(state=="left"){
//we are on the right station but no one is there
                if(!right.empty() && curr >= right[0]){//go to left
                    state="right";
                    curr+=t;
                }
                else{
                    int r=1e9,l=1e9;
                    if(!right.empty())r=right[0];
                    if(!left.empty())l=left[0];
                    if(min(l,r)!=1e9)curr=min(l,r);
                }
            }
        }
        int j=0,k=0;
        for(int i=0;i<m;i++){
            if(order[i]=="left"){
                cout<<ans_left[j]<<endl;
                j++;
            }
            else{
                cout<<ans_right[k]<<endl;
                k++;
            }
        }
        if(tt)cout<<endl;
    }
    return 0;
}