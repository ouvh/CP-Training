#include <bits/stdc++.h>

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

const int maxn = (int)1e6 + 7;
const int mod = (int)1e9 + 7;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    fast();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vi arr;
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int num;
            vi mini_arr;
            while (ss >> num) {
                mini_arr.push_back(num);
            }
            arr.push_back(mini_arr.size());
        }
        //for(int k:arr)cout<<k<<" ";cout<<endl;
        int min_number =arr[0];
        for(int i=0;i<arr.size();i++){
            min_number=min(min_number,arr[i]);
        }
        string ans ="";
        for (int i = 0; i < n; i++) {
            if (arr[i] == min_number) ans+= to_string(i+1)+" ";
        }
        ans.pop_back();
        cout<<ans<<endl;
    }
    return 0;
}
