#include <iostream>
#include <vector>

using namespace std;

int distances(vector<vector<int>> &areas, vector<int> &current_offices){
    int minimum,cost=0;
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            minimum = (int)abs(r - current_offices[0]/5) + (int)abs(c -current_offices[0]%5);
            for(int office=1;office<5;office++){
                minimum = min(minimum,(int)abs(r - current_offices[office]/5) + (int)abs(c - current_offices[office]%5));
            }
            cost += minimum * areas[r][c];
        }
    }

    return cost;
};

void solve(vector<vector<int>> &areas, vector<int> &current_offices ,vector<int> &offices,int office,int &max){
    if(office >= 5){
        int cost = distances(areas,current_offices);
        if(cost < max){
            max = cost;
            offices = current_offices;
        }
        return;
    }


    for(int i=(office == 0 ? 0:current_offices[office-1]+1);i<=25-(5-office);i++){
        current_offices[office] = i;
        solve(areas,current_offices,offices,office+1,max);

    }

}

int main(){
    int t,n,r,c;
    cin >> t;
    while(t--){
        vector<vector<int>> areas(5,vector<int>(5,0));
        vector<int> offices(5,0);
        vector<int> current_offices(5,0);
        int max = 10000000;
        cin >> n;
        for(int i=0 ;i<n;i++){
            cin >> r >> c;
            cin >> areas[r][c];
        }

        solve(areas,current_offices,offices,0,max);

        for(int i=0;i<4;i++)cout<<  offices[i] << " ";
        cout <<  offices[4] << "\n";
    }



    return 0;
}