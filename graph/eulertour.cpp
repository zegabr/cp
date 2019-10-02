
//EULER PATH == visit each edge exactly once
//EULER TOUR == euler path that start and ends at same vertice
//all except two vertices has even degrees => EULER PATH (undirected)
//at most one vertice with out - in = 1, at most one vertice eith in-out=1, every other with in==out => EULER PATH (directed)
//all vertices has even degrees  => EULER TOUR (undirected)
#include <list>
using namespace std;
list<int> cyc;

void eulertour(list<int>::iterator i, int u){
    for(auto &v : g[u]){
        if(v.second){//if vertice can be used
            v.second=0;
            for(auto &uu : g[v.first]){
                if(uu.first == u and uu.second){
                    uu.second=0;
                    break;
                }
            }
            eulertour(cyc.insert(i,u), v.first);
        }
    }
}

void findeulertour(){
    cyc.clear();
    eulertour(cyc.begin(), S); //S is start vertice
    for(list<int>::iterator it = cyc.begin(); it != cyc.end(); it++){
        cout<<*it<<endl;
    }
}
