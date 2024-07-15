#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,N,M,result;
    cin >> T;
    while(T--){
        cin >> N >> M;
        vector <int> arr1(N);
        vector <int> arr2(M);
        map <int,pair<int,int>> count;
        for(int i=0;i<N;i++)
            cin >> arr1[i];
        for(int i=0;i<M;i++)
            cin >> arr2[i];
        for(int i=0;i<N;i++)
            count[arr1[i]].first++;
        for(int i=0;i<M;i++)
            count[arr2[i]].second++;
        result = 0;
        for (const auto& pair : count)
            result += abs(pair.second.first - pair.second.second);
        cout << result << endl;
    }
    return 0;
}