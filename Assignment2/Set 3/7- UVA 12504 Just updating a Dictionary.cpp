#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    long long i,len1,len2;
    bool changed;
    string key,value;
    cin >> T;
    while(T--){
        string dic1;
        string dic2;
        cin >> dic1;
        cin >> dic2;
        map <string , string > ma1;
        map <string, string> ma2;
        for(i=1;i<dic1.length()-1;i++){
                key = dic1[i];
                i++;
                while(dic1[i] != ':'){
                    key = key + dic1[i];
                    i++;
                }
                i++;
                value = dic1[i];
                i++;
                while(dic1[i] != ',' && dic1[i] != '}'){
                    value = value + dic1[i];
                    i++;
                }
                ma1[key] = value;
        }
        for(i=1;i<dic2.length()-1;i++){
                key = dic2[i];
                i++;
                while(dic2[i] != ':'){
                    key = key + dic2[i];
                    i++;
                }
                i++;
                value = dic2[i];
                i++;
                while(dic2[i] != ',' && dic2[i] != '}'){
                    value = value + dic2[i];
                    i++;
                }
                ma2[key] = value;
        }
        len1 = ma1.size();len2 = ma2.size();
        vector <string> old_keys,new_keys,added_key,removed_key,commun_key;
        for(const auto& pair : ma1)
        old_keys.push_back(pair.first);
        for(const auto& pair : ma2)
        new_keys.push_back(pair.first);
        sort(old_keys.begin(),old_keys.end());
        sort(new_keys.begin(),new_keys.end());
        long long p1 = 0,p2 = 0;
        while(p1 < len1 && p2 < len2){
             if(old_keys[p1] == new_keys[p2]){
                 if(ma1[old_keys[p1]] != ma2[new_keys[p2]])
                 commun_key.push_back(old_keys[p1]);
                 p1++;p2++;
             }
             else if(old_keys[p1] > new_keys[p2]){
                 added_key.push_back(new_keys[p2]);
                 p2++;
             }
             else{
                 removed_key.push_back(old_keys[p1]);
                 p1++;
             }
        }
        while(p1 < len1){
            removed_key.push_back(old_keys[p1]);
            p1++;
        }
        while(p2 < len2){
            added_key.push_back(new_keys[p2]);
            p2++;
        }
        changed = false;
        if(added_key.size()){
            changed = true;
            cout << '+';
            for(i=0;i<added_key.size() -1;i++)
            cout << added_key[i] << ",";
            cout << added_key[added_key.size() -1] << endl;
        }
        if(removed_key.size()){
            changed = true;
            cout << '-';
            for(i=0;i<removed_key.size() -1;i++)
            cout << removed_key[i] << ",";
            cout << removed_key[removed_key.size() -1] << endl;
        }
        if(commun_key.size()){
            changed = true;
            cout << '*';
            for(i=0;i<commun_key.size() -1;i++)
            cout << commun_key[i] << ",";
            cout << commun_key[commun_key.size() -1] << endl;
        }
        if(!changed)
        cout << "No changes" << endl;
        cout << endl;
    }
    return 0;
}