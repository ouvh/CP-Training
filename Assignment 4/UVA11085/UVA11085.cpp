#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct layout
{
    vector<bool> rows;
    vector<bool> leftright_diag;
    vector<bool> rightleft_diag;

    layout(){
        rows.assign(8,0);
        leftright_diag.assign(15,false);
        rightleft_diag.assign(15,false);
    }

};



bool check(int r,int c,layout& legal){
    return  (legal.rows[r] == 0 && legal.leftright_diag[r+c]== 0 && legal.rightleft_diag[7-c+r] == 0);
    
}
void updatelayout(int r,int c,layout& legal,int update){
    legal.rows[r] = update;
    legal.leftright_diag[r+c] = update;
    legal.rightleft_diag[7-c+r] = update;

}


void solve(vector<int> &b,int &current, int  &minmove,int position,layout &legalmove){
    if(current >= minmove)return;


    if(position >= 8){
        if(current <= minmove){
            minmove = current;
        }
        return;
    }

    if(position == 0){

        for(int potential=0;potential<8;potential++){
            if(potential != b[position])current++;
            updatelayout(potential,position,legalmove,1);
            solve(b,current,minmove,position+1,legalmove);
            updatelayout(potential,position,legalmove,0);
            if(potential != b[position])current--;


        }
    }
    else{
        for(int potential=0;potential<8;potential++){

            if (check(potential,position,legalmove)){

                if(potential != b[position])current++;
                updatelayout(potential,position,legalmove,1);
                solve(b,current,minmove,position+1,legalmove);
                updatelayout(potential,position,legalmove,0);
                if(potential != b[position])current--;


            }

        }

    }

}


int main(){
    
    

    int t=1,temp;
    vector<int> b(8);


    while(cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7] ){
        
        layout legalmove;
        
        int currentmove = 0;
        int minmove = 8;

        for(int i=0;i<8;i++){
            b[i] = b[i] - 1 ;
        }
        
        solve(b,currentmove,minmove,0,legalmove);

        
    
        cout << "Case " << t << ": "<< minmove << "\n";
        t++;



    }


   
    return 0;
}