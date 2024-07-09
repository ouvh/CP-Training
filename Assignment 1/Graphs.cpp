#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <utility> 
#include <functional>
#include <map>
#include <cmath>
#include <queue>
#include <limits>


using namespace std;



double distance(pair<float,float> &a,pair<float,float> &b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}


class Graph{
   
    private:

        struct CompareEdge {
            bool operator()(const pair<unsigned int,double>& e1, const pair<unsigned int,double>& e2) {
                return e1.second > e2.second; 
            }
        };
        
        static vector<pair<float,float>> coordinates_map;

        struct PairComparator {
            bool operator()(const pair<unsigned int, unsigned int>& a, const pair<unsigned int, unsigned int>& b) const {
                
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

        void prim_MST() {

            size_t capacity = coordinates_map.size();
            if(capacity == 0)return;


            priority_queue<pair<unsigned int,double>, vector<pair<unsigned int,double>>, CompareEdge> pq;

            vector<double> min_to_vertex(capacity, INT_MAX);

            vector<unsigned int> parent(capacity, -1);


            vector<bool> inserted(capacity, false);

            for(size_t i=0;i<capacity;i++){

                if(!inserted[i]){

                    unsigned int root = i; 
                    parent[root] = root;
                    min_to_vertex[root] = 0;
                    pq.push({root, 0});

                    while (!pq.empty()) {

                        unsigned int front = pq.top().first;
                        pq.pop();

                        inserted[front] = true;

                        for (auto& pair : Adjlist[front]) {

                            unsigned int v = pair.first.second;
                            double weight = pair.second;

                            if (!inserted[v] && weight < min_to_vertex[v]) {

                                min_to_vertex[v] = weight;
                                parent[v] = front;
                                pq.push({v, weight});
                            }
                        }
                    }


                }

            }

            


            vector<pair<unsigned int,unsigned int>> edges(capacity);


            for(size_t i=0;i<capacity;i++){
                edges[i] = {parent[i],i};
            }
            

            sort(edges.begin(),edges.end(),[this](const pair<unsigned int, unsigned int>& a,const pair<unsigned int, unsigned int>& b)->bool{
                double weight1;
                double weight2;

                if(a.first == a.second)weight1=0;
                else weight1= Adjlist[a.first][a];

                if(b.first == b.second)weight2=0;
                else  weight2= Adjlist[b.first][b];



                return weight1 < weight2;
            });


            for(size_t i=0;i<capacity;i++){
                cout << edges[i].first << " " << edges[i].second << "\n";
            }


            
        }

        void Dijkistra(unsigned int start, unsigned int finish){

            size_t capacity = coordinates_map.size();
            if(start >= capacity || finish >= capacity)return;
            if(capacity == 0)return;
            if(start == finish){
                cout << "path : " << start << " \n";
                cout << "distance :" << 0;
            }

            priority_queue<pair<unsigned int,double>, vector<pair<unsigned int,double>>, CompareEdge> pq;
            vector<double> distances(capacity, INT_MAX);
            vector<int> predecors(capacity,-1);
            vector<bool> visited(capacity,false);
            bool arrived = false;

            distances[start] = 0;
            visited[start] = 0;
            pq.push({start, 0});



            while(!pq.empty() && !arrived){
                unsigned int front = pq.top().first;
                pq.pop();

                for (auto& pair : Adjlist[front]) {

                    unsigned int v = pair.first.second;
                    double new_distance = distances[front] +  pair.second ;
    
                    if (!visited[v] && (new_distance < distances[v])) {

                        distances[v] = new_distance;
                        predecors[v] = front;

                        if(v == finish){
                            arrived = true;
                            break;
                        }
                        else{
                            pq.push({v, new_distance});
                        }

                    }
                }

                


            };


            if(!arrived){
                cout << "Cars are disconnected , No Path\n";
                return;
            }

            vector<unsigned int> path;
            unsigned int traverse = finish;

            while(traverse != start){
                path.push_back(traverse);
                traverse = predecors[traverse];
            }
            path.push_back(start);

            for(int i=path.size()-1;i>0;i--){
                cout << path[i] << " -> " ;
            }
            cout << path[0];

            cout << "\ndistance: " << distances[finish];
            

        }

        void interface(){
            cout << "       Welcome (Thanks for providing Cars data)\n";
            int response;
            unsigned int carid;
            unsigned int carid1;
            unsigned int carid2;

            do{
                cout << "\n Choose from the menu the operation by typing the corresponding number and enter:\n";
                cout << "1) Display all edges\n2) Display Adjacent Vehicles\n3) Move a vehicule\n4) DFS\n5) BFS\n6) MST\n 7) Shortest Path\n8) Quit\n";
                cout << "you :";
                cin >> response;


                switch (response)
                {
                case 1:
                    diplay_edges();
                    break;
                case 2:
                    cout << "Car id :";
                    cin >> carid;
                    diplay_Adj_vehicules(carid);
                    break;
                case 3:
                    float x,y;

                    cout << "Car id :";
                    cin >> carid;

                    cout << "X coordinate :";
                    cin >> x;

                    cout << "Y coordinate :";
                    cin >> y;


                    move_vehicule(carid,x,y);
                    cout << "Car coordinate Updated Successfully\n";
                    break;
                case 4:

                    cout << "Car id :";
                    cin >> carid;
                    DFS(carid);
                    break;
                case 5:

                    cout << "Car id :";
                    cin >> carid;
                    BFS(carid);
                    break;

                case 6:
                    prim_MST();
                    break;
                case 7:
                 


                    cout << "Car id of the start point:";
                    cin >> carid1;

                    cout << "Car id of the finish point:";
                    cin >> carid2;

                    Dijkistra(carid1,carid2);
                    break;
                case 8:
                    cout << "Quitting";
                    break;
                
                default:
                    break;
                }

            }while(response != 8);
        }
};

vector<pair<float,float>> Graph::coordinates_map;


int main(){


    Graph graph;
    graph.parseinput();
    graph.build_Graph_based_on_Connectivity();
    graph.interface();
    
 




    return 0; 
}