#include<bits/stdc++.h>

using namespace std;
const int maxn=20,INF=(int)1e9,maxx=200;
int memo[maxn+1][maxx+1];
int n,x;

int solve(vector<vector<int>>& arr, int i,int x){
    //cout<<"here is i and x "<<i<<" "<<x<<endl;
    if(x < 0)return INF;
    if(i==arr.size())return x;
    if(memo[i][x] != -1)return memo[i][x];
    int res=INF;
    for(int element:arr[i]){
        int rr=solve(arr,i+1,x-element);
        if( rr < res){
            res=rr;
        }
    }
    return memo[i][x]=res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,kind;
        cin>>x>>kind;
        vector<vector<int>> arr(kind);
        for(int i=0;i<maxn;i++){
            memset(memo[i],-1,sizeof(memo[i]));
        }
        /*for(int i=0;i<maxn;i++){
            for(int j=0;j<maxx;j++){
                cout<<memo[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<kind;i++){
            int n;cin>>n;
            while(n--){
                int val;cin>>val;
                arr[i].push_back(val);
            }
        }

        //cout<<arr.size()<<endl;
        int res=x-solve(arr,0,x);
        //cout<<res<<endl;
        if(res > 0)cout<<res<<endl;
        else cout<<"no solution"<<endl;
    }
}