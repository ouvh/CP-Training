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
    int n;
    while(cin>>n){
//it is always better to add the smallest 2 elements
//we use min heap
if(n==0)break;
        priority_queue<int,vector<int>,greater<int>> s;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            s.push(val);
        }
        int res=0;
        while(s.size()!=1){
            //we take 2 , add them and return
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            res+=a+b;
            s.push(a+b);
        }
        cout<<res<<endl;
    }
    return 0;
}