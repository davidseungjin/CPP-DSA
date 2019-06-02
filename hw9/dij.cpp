#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define INFINITE 987654321
using namespace std;

class Graph{
private:
    vector<pair<int, pair<int, int> > > G;
    vector<pair<int, pair<int, int> > > K_MST;
    vector<pair<int, pair<int, int> > > D_MST;
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

        dijkstra(0);
//        print2();
//        kruskal();
//        print();
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
        for (i = 0; i< G.size(); i++){
            cout << "G[i].first is " << G[i].first << endl;
            cout << "G[i].second.first is " << G[i].second.first << endl;
            cout << "G[i].second.second is " << G[i].second.second << endl;
            
        sort(G.begin(), G.end());
        }
        
	for (i = 0; i < G.size(); i++){
            u_rep = find_set(G[i].second.first);
            v_rep = find_set(G[i].second.second);

            if (u_rep != v_rep){
                K_MST.push_back(G[i]); 
                union_set(u_rep, v_rep);
            }
        }
    }
    
    int minD(int dist[], bool visited[]){
        int current_min = INFINITE;
        int min_index;
        
        for(int i = 0; i < G.size(); i++){
            if(!visited[i]&&(current_min > dist[i])){
                min_index = i;
                current_min = dist[i];
            }
        }
        return min_index;
    }
    
    void dijkstra(int src){
        int dist[G.size()];
        bool visited[G.size()];
        
        for(int i = 0; i < G.size(); i++){
            dist[i] = INFINITE;
            visited[i] = false;
        }
        
        dist[src] = 0;
        
        for (int i = 0; i < (G.size()-1); i++){
            int short_path = minD(dist, visited);
            cout << "short_path index is " << short_path << endl;
         
            for(int j = 0; j < G.size(); j++){
            
                if((!visited[j]) && (G[j].first) && (dist[j]) && ((dist[short_path]+G[j].first) < dist[j] )){
                
                    cout << "G[" << j << "] second.first/second.second are \t" << G[i].second.first <<"\t"<< G[i].second.second<< endl;
                    
                    dist[j] = dist[short_path]+ G[j].first;
                
                    cout << "dist[" << j << "] is \t\t" << dist[j] << endl;
                    cout << "dist[short_path] is\t" << dist[short_path] << endl;
                    cout << "G[" << j << "].first is\t" << G[j].first << endl;
                    cout << "dist[short_path] + G[j].first is "
                    << dist[short_path] + G[j].first << endl;
                    
                }
            visited[i] = true;
            }
            
        }
/*
        int total=0;
        long unsigned int i;
        for (i = 0; i < G.size(); i++){
            cout << "G[" << i << "].second.second is " << G[i].second.second <<
            "  shortest distand from src is " << dist[i] << endl;
        }
  */
    }
    
    
//    void print2(){
//        int total=0;
//        long unsigned int i;
//        for (i = 0; i < G.size(); i++){
//            cout << G[i].second.second << endl;
//            cout << dist[i] << endl;
//        }
//    }
    
    ~Graph(){
        D_MST.clear();
        G.clear();
        delete[] vertices;
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
    
};

int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "smallgraph.txt";

    Graph a(input_file);

    return 0;
}
