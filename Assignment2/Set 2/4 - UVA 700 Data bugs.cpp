#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,y,a,b,max,count;
    long long cas =0;
    cin >> n;
    while(n != 0){
        cas++;
        vector <pair<int,int>> year;
        pair<int,int> element;
        for(int i=0;i<n;i++){
            cin >> y >> a >> b;
            element.first = y;element.second = b - a;
            year.push_back(element);
        }
        max = 0;
        for(int i=0;i<n;i++){
            if(year[i].first > max)
                max = year[i].first;
        }
        while(max < 10000){
            count = 0;
            for(int i=0;i<n;i++){
                if(year[i].first == max)
                    count++;
                else{
                    year[i].first += (ceil((max-year[i].first -1)/year[i].second) + 1)*year[i].second;
                    if(year[i].first == max)
                        count++;
                    max = year[i].first;
                }
            }
            if(count == n)
                break;
        }
        cout << "Case #" << cas << ":" << '\n';
        if(count == n)
            cout << "The actual year is " << max << "." << endl;
        else
            cout << "Unknown bugs detected." << endl;
        cout << endl;
        cin >> n;
    }

    return 0;
}