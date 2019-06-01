#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Graph{
private:
    vector<pair<int, pair<int, int> > > G;
    vector<pair<int, pair<int, int> > > K_MST;
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
        }else{
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
        if (i == vertices[i])
            return i;
        else
            return find_set(vertices[i]);
    }
    void union_set(int u, int v){
        vertices[u] = vertices[v];
    }
    void kruskal(){
        int u_rep, v_rep;
	long unsigned int i;
        sort(G.begin(), G.end()); 
    
	for (i = 0; i < G.size(); i++){
            u_rep = find_set(G[i].second.first);
            v_rep = find_set(G[i].second.second);

            if (u_rep != v_rep){
                K_MST.push_back(G[i]); 
                union_set(u_rep, v_rep);
            }
        }
    }
    void print(){
        int total=0;
        long unsigned int i;
	for (i = 0; i < K_MST.size(); i++){
            total = total + K_MST[i].first;
        }
        cout << "minimum total is: " << total << endl;
        for (i = 0; i < K_MST.size(); i++){
            cout << "["<<K_MST[i].second.first 
		<< " - " << K_MST[i].second.second << "]\t("
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
