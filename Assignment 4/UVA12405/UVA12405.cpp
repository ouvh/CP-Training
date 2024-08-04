#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct triple{
    int first;
    int second;
    int third;

};

int main(){
   


    int t,result,n;
    string s;
    cin >> t;

    for(int j=0;j<t;j++){
        result = 0;
        cin >> n;
        cin >> s;
        vector<triple> arr;
        

        for(int i=0;i<n;i++){

            if(s[i]=='#')continue;
            int start = i;
            while(s[i] == '.'){
                i++;
                if(i==n)break;
            }
            arr.push_back({start,i-1,(i-start)%3});

        }

        n = arr.size();

        for(int i=0;i<n-1;i++){
            if(arr[i+1].first - arr[i].second - 1 == 1 && arr[i].third == 1){
                result += (arr[i].second - arr[i].first + 1)/3;
                result += 1;
                if(arr[i+1].third != 0)arr[i+1].third -= 1;
            }
            else{
                result += (arr[i].second - arr[i].first + 1)/3 +( (arr[i].third != 0) ? 1:0);
            }
        }

        if(n!=0)result += (arr[n-1].second - arr[n-1].first + 1)/3 +( (arr[n-1].third != 0) ? 1:0);


        cout << "Case " << j+1 << ": "<< result << "\n";
    }




    return 0;
}