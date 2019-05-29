#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<pair<int, pair<int, int> > > G; // graph
    vector<pair<int, pair<int, int> > > K_MST; // mst
    int* vertices;
    int numvertex;
public:
    Graph(string filename){

        int value;
        int src, dst, wgt;
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
        }
        for(;;){
            if(in>> src >> dst>> wgt){
                addedge(src, dst, wgt);

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
        int i, u_rep, v_rep;
        sort(G.begin(), G.end()); // make it ascending sorting
        for (i = 0; i < G.size(); i++) {
            u_rep = find_set(G[i].second.first);
            v_rep = find_set(G[i].second.second);

            if (u_rep != v_rep) {

                K_MST.push_back(G[i]); // add to tree
                union_set(u_rep, v_rep);
            }
        }
    }
    void print(){
        int total=0;
        for (int i = 0; i < K_MST.size(); i++) {
            total = total + K_MST[i].first;
        }
        cout << "minimum total is: " << total << endl;
        for (int i = 0; i < K_MST.size(); i++) {
            cout << "["<<K_MST[i].second.first << " - " << K_MST[i].second.second << "]\t("
            << K_MST[i].first << ")" << endl;
        }
    }
    ~Graph(){
        K_MST.clear();
        G.clear();
        delete[] vertices;
    }
};

int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "rdm.graph";

    Graph a(input_file);

    return 0;
}
