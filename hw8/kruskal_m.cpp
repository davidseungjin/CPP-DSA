#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Edge{
public:
    int src;
    int dst;
    int weight;
    
public:
    Edge(int s, int d, int w)
    :src(s), dst(d), weight(w){ cout << "Edge constructor" << endl;}
    ~Edge(){
        cout << "Edge destructor" << endl;
    }
};

class Vertex{
public:
    int id;
    vector<Edge> edges;
    
public:
    Vertex()
    : id(){ cout << "Vertex constructor" << endl;}
    
    void add_edge(const Edge& e){
        e(src, dst, weight);
        cout << "src is: " << e.src << endl;
        cout << "dst is: " << e.dst << endl;
        cout << "weight is: " << e.weight << endl;
        
        //                    .src = src;
        //                    e.dst = dst;
        //                    e.weight = weight;
    }
//    {
        // push_back? what is syntax of vector?
        // inserts the Edges into the edges vector
        
//        e.push_back(make_pair(weight, make_pair(src, dst)));
//    }
    
    void print(ostream& out){}
    ~Vertex(){
        edges.clear();
        cout << "Vertex destructor" << endl;
    }
    
};


class Graph{
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
            cerr << "file not found\n";
        }
        for(int i = 0; i < num_vertex; ++i){
            Vertex& v = vertices[i];
            v.id = i;

            // anything else is necessary?
            num_edge++;            // num_of_edge counting;
            
        }
        for(;;){
            if(in >> src >> dst >> weight){
                Vertex::add_edge(const Edge& e){
                    e(src, dst, weight);
                    cout << "src is: " << e.src << endl;
                    cout << "dst is: " << e.dst << endl;
                    cout << "weight is: " << e.weight << endl;
                    
                    //                    .src = src;
                    //                    e.dst = dst;
                    //                    e.weight = weight;
                }
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
    ~Graph(){
        delete[] vertices;
    };
};




int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "smallgraph.txt";
    
    Graph a(input_file);
    
    return 0;
}
