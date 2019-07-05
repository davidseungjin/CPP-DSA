#include <iostream>
using namespace std;


struct SetNode{
    SetNode()
    :parent(this), id(0), rank(0), size(0){}
    SetNode* parent;
    int id;
    int rank;
    int size;
};

struct Set{
    int count;
    SetNode* elements;
    
    Set(int N)
    : count(N), elements(new SetNode[N]){}
    
    void error(const char * msg){
        cerr << "Error: " << msg << endl;
        exit(-1);
    }
    
    void verify_set_id(int x){
        if(x<0 || x>=count)
            error("ID out of bounds");
    }
    
    void MakeSet(int x){
        verify_set_id(x);
        SetNode& my_node = elements[x];
        
        my_node.parent = &my_node;
        my_node.rank = 0;
        my_node.size = 1;
    }
    
    SetNode* Find(SetNode* x){
        if(x->parent != x){
            x->parent = Find(x->parent);
        }
        cout << "\nFIND function" << endl;
        return x->parent;
    }
    
    SetNode* Find(int x){
        verify_set_id(x);
        SetNode& my_node = elements[x];
        return Find(&my_node);
    }
    
    void Union(int x, int y){
        SetNode* xRoot = Find(x);
        SetNode* yRoot = Find(y);
        if (xRoot == yRoot)
            return;
        if(xRoot -> size < yRoot -> size)
            swap(xRoot, yRoot);
        yRoot -> parent = xRoot;
        xRoot -> size = xRoot -> size + yRoot -> size;
    }
};

void make_all_sets(Set& a, int N){
    for(int i = 0; i < N; i++)
        a.MakeSet(i);
}

void find_all_sets(Set& a, int N){
    for(int i=0; i < N; i++)
        cout << i << " set is " << a.Find(i) << endl;
}

void union_all_sets(Set& a, int N){
    for(int i=0; i < N; ++i)
        a.Union(0,i);
}

void print_sets(Set& a, int N){
    for (int i=0; i < N; ++i)
        cout << i << " set is " << a.Find(i) << endl;
}


int main(){
    const int N = 100;
    Set a(N);
    
    make_all_sets(a, N);
    find_all_sets(a, N);
    union_all_sets(a, N);
    find_all_sets(a, N);
    print_sets(a, N);
    
    return 0;
}



