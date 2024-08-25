#include <iostream>
 
using namespace std;
 
 
int main(){
    
    int n,sx,sy,x,y;
    int score[4] = {0,0,0,0};
    cin >> n >> sx >> sy;
    
    for(int i=0;i<n;i++){
        cin >> x >> y;
        
        if (min(sy,y)<= sy + 1  && sy + 1 <= max(sy,y))score[0]++;
        if (min(sx,x)<= sx + 1  && sx + 1 <= max(sx,x))score[1]++;
        if (min(sy,y)<= sy - 1  && sy - 1 <= max(sy,y))score[2]++;
        if (min(sx,x)<= sx - 1  && sx - 1 <= max(sx,x))score[3]++;
 
 
        
    }
    int m = max(score[0],max(score[1],max(score[2],score[3])));
    if(score[0] == m)cout << score[0] << "\n" << sx << " " << sy+1 ;
    else if(score[1] == m)cout << score[1] << "\n" << sx+1 << " " << sy ;
    else if(score[2] == m)cout << score[2] << "\n" << sx << " " << sy-1 ;
    else if(score[3] == m)cout << score[3] << "\n" << sx - 1 << " " << sy ;
 
 
    
    
    
    return 0;
}