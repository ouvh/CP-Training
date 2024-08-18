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
    int n;cin>>n;
    vvi matrix(n,vi (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int maxsum =- 127*100*100-5;
    for(int left=0;left<n;left++){
        vi rs(n,0);
        for(int right=left;right<n;right++){
            for(int i=0;i<n;i++)rs[i]+=matrix[i][right];
            //for(int i=0;i<n;i++)cout<<rs[i]<<" ";cout<<endl;

            //we should applu kadan on our rs now
            int sum=0;
            for(int i=0;i<n;i++){
                sum=max(rs[i],sum+rs[i]);
                if(sum>maxsum)maxsum=sum;
            }

        }
    }
    cout<<maxsum<<endl;
    return 0;
}