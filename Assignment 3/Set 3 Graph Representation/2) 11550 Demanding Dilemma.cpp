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
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vvi arr(n,vi (m)),adj(n,vi(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        bool res=true;
        for(int j=0;j<m;j++){
            int count=0;
            int x=-1;
            for(int i=0;i<n;i++){
                count+=arr[i][j];
                if(arr[i][j]==1){
                    if(x==-1)x=i;
                    else {
                        if(adj[i][x]==1)res=false;
                        adj[i][x]=1;
                        adj[x][i]=1;    }
                }
            }
            if(count!=2)res=false;
        }
        if(res)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}