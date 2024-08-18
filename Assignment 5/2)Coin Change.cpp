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
int dp[5][7490];
vector<int> coins={1,5,10,25,50};

int solve(int index,int num){
    if(num == 0)return 1;
    if(num < 0)return 0;
    if(index == 5)return 0;
    if (dp[index][num]!=-1)return dp[index][num];
    return dp[index][num]=
                   solve(index+1 , num)+
                   solve(index , num-coins[index]);
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    int n;
    while(cin>>n){
        cout<<solve(0,n)<<endl;
    }
    return 0;
}