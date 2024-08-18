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

const int maxn=1002;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m,dp[maxn][maxn];
string a,b;

int solve(int i,int j){
    if(i==n || j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int res;
    if(a[i]==b[j]){
        res=1+solve(i+1,j+1);
    }
    else {
        res=max(
                solve(i+1,j),
                solve(i,j+1)
        );
    }

    return dp[i][j]=res;
}

int main(){fast();
    while(getline(cin,a)){
        getline(cin,b);
        memset(dp,-1,sizeof(dp));
        n=a.size();
        m=b.size();
        cout<<solve(0,0)<<endl;
    }
    return 0;
}