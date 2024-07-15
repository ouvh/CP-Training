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
    string word;int kk=0;
    while(cin>>word){kk++;
        if(word=="end")break;
        int count=0;
        //A should be on top of the stack
        while(word.size()>0){
            int n=word.size();
            stack<int> s;
            s.push(word[0]);
            for(int i=1;i<n;i++){
                while(!s.empty() && s.top() < word[i]){//can't put it on top
                    s.pop();
                }
                s.push(word[i]);
            }

            //now we need to remove elements
            int index=n-1;
            while(!s.empty()){
                if(word[index]==s.top()) {
                    word.erase(index, 1);
                    s.pop();
                }
                index--;
            }
            count++;
        }
        cout<<"Case "<<kk<<": "<<count<<endl;
    }
    return 0;
}