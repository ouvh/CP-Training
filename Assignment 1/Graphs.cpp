#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <utility> 
#include <functional>
#include <map>
#include <cmath>
#include <queue>


using namespace std;




double distance(pair<float,float> &a,pair<float,float> &b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}


class Graph{
   
    private:
        
        static vector<pair<float,float>> coordinates_map;

        struct PairComparator {
            bool operator()(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b) const {
                
                    return distance(Graph::coordinates_map[a.first],Graph::coordinates_map[a.second]) < distance(Graph::coordinates_map[b.first],Graph::coordinates_map[b.second]);
                
            }
        };

        vector<map<pair<unsigned int,unsigned int>,double,PairComparator>> Adjlist;

        void DFS_helper(unsigned int id,vector<bool> &visited){
            visited[id] = true;
            cout << id << " ";

            for ( auto& pair : Adjlist[id]) {
                if(visited[pair.first.second])continue;
                DFS_helper(pair.first.second,visited);
            }

        }

    public:

        float Connectivity_Range;

        void addvertex(float x,float y){
            coordinates_map.push_back(pair<float,float>(x,y));
            Adjlist.push_back({});
        }
        
        void addedge(unsigned int a, unsigned int b){

            pair<unsigned int,unsigned int> temp1(a,b);
            pair<unsigned int,unsigned int> temp2(b,a);

            Adjlist[a][temp1] = distance(coordinates_map[a],coordinates_map[b]);
            Adjlist[b][temp2] = distance(coordinates_map[a],coordinates_map[b]);


        }

        void build_Graph_based_on_Connectivity(){
            size_t capacity = coordinates_map.size();
            vector<bool> temp(capacity);

            for(int id1=0;id1<capacity;id1++){
                temp[id1] = true;
                for(int id2=0;id2<capacity;id2++){
                    if(id1 == id2)continue;
                    if(temp[id2])continue;
                    if(check_connectivity(id1,id2))addedge(id1,id2);

                }
            }
        }

        bool check_connectivity(unsigned int a,unsigned int b){
            return distance(coordinates_map[a],coordinates_map[b]) < Connectivity_Range;
        }

        void parseinput(){

            size_t capacity;
            scanf("%zu",&capacity);
            scanf("%f",&Connectivity_Range);
            for (size_t i = 0; i < capacity; i++){
                float a;
                float b;
                scanf("%f%f",&a,&b);
                addvertex(a,b);
            }
            

        }

        void diplay_edges(){
            size_t capacity = coordinates_map.size();

            for(int id1=0;id1<capacity;id1++){

                for ( auto& pair : Adjlist[id1]) {
                    printf("(%d, %d, %.3g)\n",pair.first.first,pair.first.second,pair.second);
                }
            }
        }
        
        void diplay_Adj_vehicules(unsigned int id){
            size_t capacity = coordinates_map.size();
            if (id >= capacity)return;


            for ( auto& pair : Adjlist[id]) {
                printf("\n(%d, %.3g)\n",pair.first.second,pair.second);
            }
            
        }

        void move_vehicule(unsigned int id, float x, float y){

            size_t capacity = coordinates_map.size();
            if(id>= capacity)return;


            coordinates_map[id] = pair<float,float>(x,y);

            for ( auto& pair : Adjlist[id]) {
                Adjlist[pair.first.second].erase({pair.first.second,pair.first.first});
            }
            
            Adjlist[id].clear();

            for(int id2=0;id2<capacity;id2++){
                    if(id == id2)continue;
                    if(check_connectivity(id,id2))addedge(id,id2);

            }



        }

        void DFS(unsigned int id){

            size_t capacity = coordinates_map.size();
            if(id >=capacity)return;

            vector<bool> visited(capacity,false);

            DFS_helper(id,visited);
            cout << "\n";

        }

        void BFS(unsigned int id){
            size_t capacity = coordinates_map.size();
            if(id >=capacity)return;

            vector<bool> visited(capacity,false);
            queue<unsigned int> Queue;

            Queue.push(id);
            visited[id] = true;

            while(!Queue.empty()){
                unsigned int front = Queue.front();
                Queue.pop();

                cout << front << " ";

                for ( auto& pair : Adjlist[front]) {
                    if(visited[pair.first.second]) continue;
                    visited[pair.first.second] = true;
                    Queue.push(pair.first.second);
                }


            }

            cout << "\n";

        }
};

vector<pair<float,float>> Graph::coordinates_map;


int main(){



    Graph graph;
    graph.parseinput();
    graph.build_Graph_based_on_Connectivity();
    
    graph.DFS(0);
    cout << "Hello\n";
    graph.BFS(0);




    return 0;
}