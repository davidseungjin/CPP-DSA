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
    Vertex(int i)
    : id(i){ cout << "Vertex constructor" << endl;}
    
    void add_edge(Edge& e){

        edges = e;
//        e.src = 2;
//        e.dst = 3;
//        e.weight = 4;
        cout << e.src << endl << e.dst << endl << e.weight;
//        (2,3,4);
    }
//    {
        // push_back? what is syntax of vector?
        // inserts the Edges into the edges vector
        
//        e.push_back(make_pair(weight, make_pair(src, dst)));
//    }
    
    void print(ostream& out){}
    ~Vertex(){
        cout << "Vertex destructor" << endl;
    }
};

/*
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
            cout << v.id << endl;
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
 
     Constructor that takes in a .graph file; it should open the file and initialize this Graph using the data in the file**, assume that the file is valid
 
    void add_edge(int src, int dst, int weight){
        cout << "src/dst/weight are: \t" << "src:" <<src << "\tdst:" << dst << "\tweight:" << weight << endl;
        
        vertices->edges = Edge(src, dst, weight); //void Vertex::add_edge(const Edge& e)<< endl;
    }

     Adds a new edge with the given values to the appropriate Vertex(s) in this Graph

    ~Graph(){
        delete[] vertices;
    }
};
*/



int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "smallgraph.txt";
    
//    Graph a(input_file);
    Vertex a(3);
    Edge b(5,6,7);
    a.add_edge(b);
    
    return 0;
}
