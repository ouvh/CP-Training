#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool check(int bitmask,int s,int d){
    int sum = 0;
    int previous = bitmask;
    for(int i=0;i<5;i++){
        sum += ( (1 & bitmask) ? s:-d);
        bitmask = bitmask >> 1;
    }
    if(sum >= 0)return false;

    for(int i=0;i<7;i++){
        sum = sum + ( (1 & bitmask) ? s:-d) - (( (1 & previous) ? s:-d));
        if(sum>=0)return false;
        previous = previous >> 1;
        bitmask = bitmask >> 1;
    }
    return true;
}

int backtrack(int s, int d, int position,int bitmask,int active){

    if(position == 11){
        bool surplus = check(bitmask | (1<<position),s,d);
        if(surplus)return active+1;
        else return active;
    }

    bool surplus = check(bitmask | (1<<position),s,d);

    if(surplus) return max(backtrack(s,d,position+1,bitmask,active),backtrack(s,d,position+1,bitmask | (1<<position),active+1));
    else return backtrack(s,d,position+1,bitmask,active);

}




int main(){
   


    int s,d,result;


    while(cin >> s >> d){
        result = backtrack(s,d,0,0,0);
        result = result*s - (12-result)*d;
        if(result > 0) cout << result << "\n";
        else cout << "Deficit" << "\n";
        
    }


    return 0;
}