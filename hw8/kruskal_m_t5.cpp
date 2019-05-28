#include <iostream>
#include <vector>
#include <fstream>
//#include <algorithm>
using namespace std;

//#define edge pair<int,int>

class Graph {
private:
    vector<pair<int, pair<int, int> > > G; // graph
    vector<pair<int, pair<int, int> > > T; // mst
    int *vertices;
    int numvertex; // number of vertices/nodes in graph
public:
    Graph(string filename){

//    cout << "test constructor" << endl;

        int value;
        int src, dst, weight;
        ifstream in(filename);
        if(in >> value){
            numvertex= value;
            vertices = new int[numvertex];
        }
        else{
            cerr << "file not found\n";
        }
        for (int i = 0; i < numvertex; ++i){
            vertices[i] = i;
            cout << "vertices[" << i << "] is : " << vertices[i] << endl;
            
        }
        for(;;){
            if(in>> src >> dst>> weight){
                addedge(src, dst, weight);
//                cout << "src, dst, weight is\t" << src << "\t" << dst << "\t" << weight << endl;
            }else{
                break;
            }
        }
        in.close();
        
        kruskal();
        print();
    }
    void addedge(int u, int v, int w){
        G.push_back(make_pair(w, make_pair(u, v)));
    }
    int find_set(int i){
        // If i is the vertices of itself
        if (i == vertices[i])
            return i;
        else
            // Else if i is not the vertices of itself
            // Then i is not the representative of his set,
            // so we recursively call Find on its vertices
            return find_set(vertices[i]);
    }
    
    void union_set(int u, int v){
        vertices[u] = vertices[v];
    }
    
    void kruskal(){
        int i, uRep, vRep;
        sort(G.begin(), G.end()); // ascending sorting
        for (i = 0; i < G.size(); i++) {
            uRep = find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            cout << "3.   kruskal for-statement\n";

            if (uRep != vRep) {

                T.push_back(G[i]); // add to tree
                union_set(uRep, vRep);
            }
        }
    }
    
    void print(){
//        cout << "Edge :" << " Weight" << endl;
        int total=0;
        for (int i = 0; i < T.size(); i++) {
            total = total + T[i].first;
//            total += T[i].first;
//            cout << total << endl;
            cout << endl;
        }
        cout << "minimum total is: " << total << endl;
        for (int i = 0; i < T.size(); i++) {
            cout << T[i].second.first << " - " << T[i].second.second << " : "
            << T[i].first;
            cout << endl;
        }
        
    }
    ~Graph(){
        T.clear();
        G.clear();
        delete[] vertices;
        cout << "destructor called" << endl;
    }
};


int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "rdm.graph";
    

	cout << "test" << endl;

    Graph a(input_file);

    return 0;
}
