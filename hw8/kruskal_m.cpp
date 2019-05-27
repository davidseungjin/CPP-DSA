#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



class Edge
{
public:
    int src;
    int dst;
    int weight;
    
public:
    Edge(int s, int d, int w)
    :src(s), dst(d), weight(w){}
    ~Edge();
};

class Vertex{
public:
    int id;
    vector<Edge> edges;
    
public:
    Vertex()
    : id(0), edges(0){}
    
    void add_edge(const Edge& e){
        // push_back? what is syntax of vector?
        // inserts the Edges into the edges vector
    }
    
    void print(ostream& out){}
    ~Vertex();
    
};

class Graph
{
    int num_edge;
    int num_vertex;
    Vertex* vertices;
    
public:
    Graph(string filename){
        int value, src, dst, weight;
        ifstream in(filename);
        if(in >> value){
            num_vertex = value;
            vertices = new Vertex[num_vertex];
        }else{
            cout << "file not found\n";
        }
        for(int i = 0; i < num_vertex; ++i){
            Vertex& v = vertices[i];
            v.id = i;
            // anything else is necessary?
            
        }
        for(;;){
            if(in >> src >> dst >> weight){
                add_edge(src, dst, weight);
            }else{
                break;
            }
        }
        in.close();
    }
    /*
     Constructor that takes in a .graph file; it should open the file and initialize this Graph using the data in the file**, assume that the file is valid
     */
    
    void add_edge(int src, int dist, int weight){}
    /*
     Adds a new edge with the given values to the appropriate Vertex(s) in this Graph
    */
    ~Graph();
};




int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "smallgraph.txt";
    
    Graph a(input_file);
    
    return 0;
}
