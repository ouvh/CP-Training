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

int main(){
    int t;cin>>t;
    int tt=0;
    while(t--){tt++;
        int n;cin>>n;
        n--;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //basic kadenes;
        int res=0,start=0,end__=0,start_curr=0,end_curr=0,curr=0;
        for(int i=0;i<n;i++){
            if(arr[i] > curr+arr[i]){
                curr=arr[i];
                start_curr=i;
                end_curr=i;
            }
            else{
                curr+=arr[i];
                end_curr=i;
            }
            if(curr > res || (curr==res && end_curr-start_curr > end__-start)){
                res=curr;
                start=start_curr;
                end__=end_curr;
            }
        }

        if(res!=0)
            cout<<"The nicest part of route "<<tt<<" is between stops "<<start+1<<" and "<<end__+2<<endl;
        else printf("Route %d has no nice parts\n",tt);
    }
    return 0;
}
