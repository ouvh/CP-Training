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
    int tt; cin >> tt;
    //cin.ignore(); // Ignore the newline after the number of test cases
    while (tt--) {
        int p, t;
        cin >> p >> t;
        cin.ignore(); // Ignore the newline after the p and t input
        vector<bool> visited(p+1,false);
        map<int, set<int>> data;
        //cout << p << " " << t << endl;
        string line;
        while (getline(cin, line)) {
            if (line.empty()) break;
            //cout << "here is line: " << line << endl;
            stringstream ss(line);
            int person, tree;
            ss >> person >> tree;
            visited[person]=true;
            data[person].insert(tree);
        }
        if(p==0){cout<<0<<endl;continue;}
        // Now we will have a set of sets and find its length
        set<set<int>> res;
        for (auto& elem : data) {
            res.insert(elem.second);
        }
        int toadd=0;
        for(int i=0;i<p;i++){
            if(!visited[i+1]){
                toadd=1;
                break;
            }
        }
        cout << res.size()+toadd << endl;
        if (tt) cout << endl;
    }
    return 0;
}


