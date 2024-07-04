#include <iostream>
#include <unordered_map>
#include <utility> 
#include <functional>
#include <map>


using namespace std;


struct Vehicule{

    unsigned int id;
    pair<float,float> coordinates;

    bool operator==(const Vehicule& other) const {
        return id == other.id;
    }

    Vehicule():id(0),coordinates({0,0}){}

    Vehicule(unsigned int id,float x, float y):id(id),coordinates({x,y}){}

};

struct VehiculeHash {

    size_t operator()(const Vehicule& v) const {
        return hash<unsigned int>()(v.id);
    }

};



class Graph{

    private:
        unsigned int availableid;
        unordered_map<Vehicule,map<unsigned int,double>,VehiculeHash> Adjlist;

    public:
        void addvertex(float x,float y){

            Vehicule newvehicule(availableid,x,y);
            Adjlist[newvehicule] = {};
            availableid++;

        }







        Graph():availableid(0){   //constructor
        }






};

