#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#define INF 77777

using namespace std;

class Graph{
public:
    int src, dst, wgt;
    int V, E;
    vector<vector<int> > graph;
    
public:
    Graph(string filename, int num){
        ifstream in(filename);
        in >> V;

        graph.assign(V, vector<int>(V,INF));
        for(;;){
            if(in>>src>>dst>>wgt){
                graph[src][dst] = wgt;
                E++;
            }else{
                break;
            }
        }
        in.close();
        dijkstra(graph, num);
    }

    void pathfinder(int prev[], int j){
        if (prev[j] == - 1){
            cout << j ;
            return;
        }
        pathfinder(prev, prev[j]);
        cout << "-" << j;
    }

    void printSolution(int dist[], int n, int prev[]){
        int src = 0;
        for (int i = 0; i < V; i++){
            cout << i << "\t"<< "\t";
            cout << "[" ;
            pathfinder(prev, i);
            cout << "]" << " (" << dist[i] << ")" << endl;
        }
    }
    
    int minVindex(int dist[], bool check_visit[]){
        int min = INF;
        int min_index;
        for (int v = 0; v < V; v++){
            if (check_visit[v] == false && dist[v] < min){
                min = dist[v], min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(vector<vector<int> > graph, int src){
        int dist[V];
        bool check_visit[V];
        int prev[V];

        for (int i = 0; i < V; i++){
            prev[src] = -1;
            dist[i] = INF;
            check_visit[i] = false;
        }

        dist[src] = 0;
        for (int i = 0; i < V - 1; i++){
            int u = minVindex(dist, check_visit);
            check_visit[u] = true;
            for (int v = 0; v < V; v++){
                if (!check_visit[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                    prev[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        printSolution(dist, V, prev);
    }
};

int main(int argc, char* argv[]){
    if(argc != 3){
        
        cout << "This program should have two arguments.\n\nThe first one should be a starting vertex. \nThe second one should be the graph file name.\nFirst line contains number of vertex, \nfollowed by remaining lines src/dst/wgt\n";
    }else{
    
        cout << "argv[1] is " << argv[1] << endl;
        int num = atoi(argv[1]);
        cout << "num is " << num << endl;
        cout << "num + 1 is " << num + 1 << endl;
        Graph a(argv[2], num);
        
    }
    return 0;
}
