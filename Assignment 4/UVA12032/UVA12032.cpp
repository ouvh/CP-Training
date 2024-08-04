#include <iostream>
#include <vector>


using namespace std;

bool verify(int k,vector<int> &arr){
    int n = arr.size();
    int previous = 0;
    for(int i=0;i<n;i++){
        if(arr[i]-previous > k)return false;
        if(arr[i]-previous == k)k--; 
        previous  = arr[i];       
    }
    return true;
}


int main(){
    int t,n;

    cin >> t;

    for(int j=0;j<t;j++){
        cin >> n;
        int MIN = 0;
        int MAX = 0;
        int previous = 0;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
            MAX = max(MAX,arr[i]-previous); 
            previous = arr[i];       
        }
        MAX++;


        while(MAX - MIN > 1){

            int c = (MAX + MIN) / 2;
            if(verify(c,arr)){
                MAX = c;
            }
            else{
                MIN = c;
            }
        }
        if(verify(MAX,arr))cout << "Case " << j+1 << ": "<< MAX << "\n";
        else cout << "Case " << j+1 << ": "<< MIN << "\n";






        
    }



    return 0;
}