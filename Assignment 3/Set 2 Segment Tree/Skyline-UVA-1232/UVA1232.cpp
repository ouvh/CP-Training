#include <iostream>
#include <cstdio>
#include <utility> 
#include <limits>
#include <vector>
#include <cmath>



using namespace std;

struct Node{
    pair<int,int> boundary;
    int height;
    vector<Node> children;

    Node(int low,int high,int height):boundary({low,high}),height(height){
    };

    Node(){
    };

};

int DFS(Node &root,int low ,int high,int height){
    int score = 0;
    // it is a leaf of the tree
    if(root.children.size() == 0){

        // create chidren based on the interscetion




        if(root.boundary.first < low){

            if( high < root.boundary.second){


                if(root.height <= height){
                    score+= high  -  low;
                    root.children.push_back(Node(root.boundary.first,low,root.height));
                    root.children.push_back(Node(low,high,height));
                    root.children.push_back(Node(high,root.boundary.second,root.height));

                }
               


            }else{

                 if(root.height <= height){
                    score+= root.boundary.second - low;
                    root.children.push_back(Node(root.boundary.first,low,root.height));
                    root.children.push_back(Node(low,root.boundary.second,height));

                }


            }



        }
        else{

            if( high < root.boundary.second){


                if(root.height <= height){

                    score+= high - root.boundary.first;
                    root.children.push_back(Node(root.boundary.first,high,height));
                    root.children.push_back(Node(high,root.boundary.second,root.height));

                }
               


            }else{

                if(root.height <= height){
                    score+= root.boundary.second - root.boundary.first;
                    root.height = height;
                }


            }






        }







    }
    else{

        for(auto & child:root.children){
            //check intersection
            if(low >= child.boundary.second || high <= child.boundary.first){
                continue;
            }
            else{
                score += DFS(child,low,high,height);
            }

        }
    }


    return score;

}


int handle_dataset(int n){

    int ss = 0;
    Node root(0,1000000,0);

    int low;
    int high;
    int height;

    for(int i=0;i<n;i++){
        cin >> low >> high >> height;
        ss += DFS(root,low,high,height);
    }

    return ss;

}


int main(){

    int c;
    int n;
    cin >> c;

    for(int j=0;j<c;j++){
        cin >> n;
        cout << handle_dataset(n) << "\n";
    }

    



    return 0;
}