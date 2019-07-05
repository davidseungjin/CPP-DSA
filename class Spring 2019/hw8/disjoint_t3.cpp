#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// parents node
int getParent(int parent[], int node){
    if(parent[node] == node) {
        return node;
    }
    return getParent(parent, parent[node]);
}

// union: parents node
int unionParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x < y){
        parent[y] = x;
        return x;
    }else {
        parent[x] = y;
        return y;
    }
}

// find and check whether or not same parents
int findParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x == y){
        // same parents
        return 1;
    }else{
        // different parents
        return 0;
    }
}

// information of edges
class Edge{
public:
    int node[2];
    int distance;
    Edge(int x, int y, int distance){
        this->node[0] = x;
        this->node[1] = y;
        this->distance = distance;
    }
    bool operator <(Edge &edge){
        return this->distance < edge.distance;
    }
};

int main(int argc, char* argv[]) {
    int n = 7; // number of vertex
    int m = 11; // number of edge
    vector<Edge> v;
    
    v.push_back(Edge(1, 7, 12)); // 1
    v.push_back(Edge(4, 7, 13)); // 2
    v.push_back(Edge(1, 4, 18)); // 3
    v.push_back(Edge(1, 2, 67)); // 4
    v.push_back(Edge(1, 5, 17)); // 5
    v.push_back(Edge(2, 4, 24)); // 6
    v.push_back(Edge(2, 5, 62)); // 7
    v.push_back(Edge(3, 5, 20)); // 8
    v.push_back(Edge(3, 6, 37)); // 9
    v.push_back(Edge(5, 6, 45)); // 10
    v.push_back(Edge(5, 7, 73)); // 11
    
    // ascending ordser
    sort(v.begin(), v.end());
    
    // initialization
    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)){
            // what if there's no cycle (because of having different parents)
            sum += v[i].distance;
            // Because of having same parents after connected
            unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
        }
// end if
    }
// end for
    
    // result verification
    cout << sum;
    
    return 0;
}

