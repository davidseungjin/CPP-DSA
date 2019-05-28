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
    int V; // number of vertices/nodes in graph
public:
    Graph(string filename){
        
//i 0 1 2 3 4 5
//vertices[i] 0 1 2 3 4 5

	cout << "test constructor" << endl;

        int value;
        int src, dst, weight;
        ifstream in(filename);
        cout << "2.     test\n";
        if(in >> value){
            cout << "3.     test\n";
            V= value;
            cout << "4.     test\n";
            vertices = new int[V];
        }
//        else{
//            cerr << "file not found\n";
//        }
        cout << "5.     test\n";
        for (int i = 0; i < V; ++i){
            vertices[i] = i;
            cout << "vertices[" << i << "] is : " << vertices[i] << endl;
            cout << "6.     test\n";
            
        }
        cout << "7.     test\n";
        for(;;){
                cout << "8.     test\n";
            if(in>> src >> dst>> weight){
                cout << "9.     test\n";
                AddWeightedEdge(src, dst, weight);
//                G.push_back(make_pair(weight, edge(src, dst)));
                cout << "src, dst, weight is\t" << src << "\t" << dst << "\t" << weight << endl;
            }else{
                cout << "before break" << endl;
                break;
            }
        }
        in.close();
        
//        G.clear();
//        T.clear();
        kruskal();
        print();
        
    }
    void AddWeightedEdge(int u, int v, int w){
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
        cout << "1.   kruskal begin\n";
        int i, uRep, vRep;
        sort(G.begin(), G.end()); // increasing weight
        cout << "2.   kruskal begin\n";
        for (i = 0; i < G.size(); i++) {
            uRep = find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            cout << "3.   kruskal for-statement\n";

            if (uRep != vRep) {
                cout << "4.   kruskal if\n";

                T.push_back(G[i]); // add to tree
                union_set(uRep, vRep);
            }
        }
    }
    
    void print(){
        cout << "Edge :" << " Weight" << endl;
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
