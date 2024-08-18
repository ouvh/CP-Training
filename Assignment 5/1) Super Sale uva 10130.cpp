//link https://vjudge.net/problem/UVA-10130
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

const int maxn=(int)1001;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n;
vector<ii> arr(maxn);
int dp[maxn][31],max_w;

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i].f>>arr[i].s;
//here f is price and s is weight
        }

        for(int w=0;w<31;w++){
            dp[0][w]= w- arr[0].s >=0 ? arr[0].f :0;
        }

        for (int i = 1; i < n; i++) {
            for(int w=0;w < 31;w++){
                dp[i][w]=dp[i-1][w];
                if(arr[i].s <= w){
                    dp[i][w]=max(
                            arr[i].f+dp[i-1][w-arr[i].s]
                            ,dp[i][w]);
                }
            }
        }

        int res=0;
        int g;cin>>g;
        for(int i=0;i<g;i++){
            cin>>max_w;
            res+=dp[n-1][max_w];
        }
        cout<<res<<endl;
    }
    return 0;
}