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

int n,m;


int main(){fast();
    while(cin>>n>>m){
        if(n==0)break;
        vvi arr(n,vi(m,0)),lis_down(n,vi(m,1)),lis_right(n,vi(m,1));
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        //we iterate over columns twice :)
        int res=1;
        for(int left=0;left<m;left++){
            vi sum(n,0);
            for(int right=left;right<m;right++){
                int dist=right-left+1;
                for(int i=0;i<n;i++){
                    if(right==left)
                        sum[i]=1;
                    else if(arr[i][right] > arr[i][right-1]){
                        sum[i]++;
                    }
                }
//now we need to count lis (continous) on rows where their sum is equal to dist

                int count=0,lis_rows=0;
                //if(left==right && right==3)cout<<count<<endl;

                for(int i=0;i<n;i++){
                    //if(left==right && right==3)cout<<sum[i]<<endl;
                    if(sum[i]==dist && (count==0 || arr[i-1][right] < arr[i][left])){
                        count++;
                    }
                    else if(sum[i]==dist)count=1;
                    else{
                        count=0;
                    }
                    lis_rows=max(lis_rows,count);
                }

                res=max(res,dist*lis_rows);
            }
        }


        cout<<res<<endl;
    }
    return 0;
}

/*
 2 2
-290050 -998003
434904 613561
 */