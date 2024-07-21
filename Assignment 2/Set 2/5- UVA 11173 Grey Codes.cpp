#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,n;
    long long k,result;
    cin >> N;
    while(N--){
        cin >> n >> k;
        int i;
        char binary[n],gray[n];
        for(i=0;i<n;i++)
            binary[i] = '0';
        i = n-1;
        while(k > 0){
            binary[i] = char(k%2 + 48);
            k /= 2;
            i--;
        }
        gray[0] = binary[0];
        for(i =1;i<n;i++)
            gray[i] = char(48 + (int(binary[i-1] - '0')^int(binary[i] - '0')));
        result = 0;
        for(i = n-1;i>=0;i--){
            if(gray[i] == '1')
                result += pow(2,n- i -1);
        }
        cout << result << endl;
    }
    return 0;
}

