/* Directed Graphs
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */
#include <cstdio>

/*--- DGraph ----------------------------------------------------------------*/
const long INFINITE_DIST = 100000000;

/*--- Directed Graph Classes ------------------------------------------------*/

/* --- Directed graph edge class ---
 * Each edge object represents an outgoing edge of some vertex and is stored in
 * that vertexes linked list of edges.   The member 'target' is the edge's
 * target vertex number, whereas 'source' is the edge's source vertex number.
 * The member 'dist' is the associated edge distance.  The pointers 'nextIn'
 * and 'nextOut' are used to form a linked lists of a vertices incoming and
 * outgoing edges respectively.  Such linked lists are terminated with a null
 * pointer.
 */
class DGraphEdge {
public:
    int source, target;
    int dist;
    DGraphEdge *nextOut, *nextIn;
};

/* --- Directed graph vertex class ---
 * Each vertex object has an associated linked lists of edge objects
 * representing the outgoing and incoming edges of that vertex.  The member
 * pointers outHead and inHead points to the first edge object in the linked
 * list of outgoing, and incoming edges respectively.  Similarly, outTail and
 * inTail point to the last edge of each linked list.  The number of outgoing
 * and incoming edges are stored in outSize and inSize respectively.
 */
class DGraphVertex {
public:
    DGraphEdge *outHead, *outTail;
    DGraphEdge *inHead, *inTail;
    int outSize, inSize;
};

/* --- Directed graph class ---
 * Vertices in the graph are stored as an array of vertex objects, pointed to
 * by the member variable 'vertices'.  Each vertex is identified by a number
 * corresponding to its index in the vertices[] array.  The member
 * nVertices is the number of vertices in the graph.
 *
 * clear()      - Remove all edges from graph.
 *
 * addNewEdge() - Adds a new edge to the edge to the graph.
 *
 * print()      - Prints a text representation of the graph to the standard
 *                output.
 */
class DGraph {
public:
    int nVertices;
    DGraphVertex *vertices;
    
    DGraph::DGraph(int n);
    DGraph::~DGraph();
    
    void clear();
    void addNewEdge(int srcVertexNo, int destVertexNo, int dist);
    bool edgeExists(int v, int w) const;
    bool reachable(int s) const;
    void print() const;
private:
    void initVertices();
};

/* --- Constructor ---
 * Creates a DGraph object containing n vertices.
 */
DGraph::DGraph(int n)
{
    nVertices = n;
    
    vertices = new DGraphVertex[n];
    initVertices();
}

/* --- Destructor ---
 */
DGraph::~DGraph()
{
    clear();
    delete [] vertices;
}

/* --- clear() ---
 * Clears all edges from the graph.
 */
void DGraph::clear()
{
    DGraphEdge *edge, *nextEdge;
    for(int i = 0; i < nVertices; i++) {
        edge = vertices[i].outHead;
        
        while(edge) {
            nextEdge = edge->nextOut;
            delete edge;
            edge = nextEdge;
        }
    }
    initVertices();
}

void DGraph::initVertices()
{
    for(int i = 0; i < nVertices; i++) {
        vertices[i].outHead = vertices[i].outTail = 0;
        vertices[i].inHead = vertices[i].inTail = 0;
        vertices[i].outSize = vertices[i].inSize = 0;
    }
}

/* --- addNewEdge() ---
 * Adds a new edge from vertex 'source' to vertex 'target' with
 * with a corresponding distance of dist.
 */
void DGraph::addNewEdge(int source, int target, int dist)
{
    DGraphEdge *newEdge = new DGraphEdge;
    newEdge->source = source;
    newEdge->target = target;
    newEdge->dist = dist;
    newEdge->nextOut = NULL;
    newEdge->nextIn = NULL;
    
    DGraphVertex *vertex = &vertices[source];
    if(vertex->outTail) {
        vertex->outTail->nextOut = newEdge;
    }
    else {
        vertex->outHead = newEdge;
    }
    vertex->outTail = newEdge;
    vertex->outSize++;
    
    vertex = &vertices[target];
    if(vertex->inTail) {
        vertex->inTail->nextIn = newEdge;
    }
    else {
        vertex->inHead = newEdge;
    }
    vertex->inTail = newEdge;
    vertex->inSize++;
};

bool DGraph::edgeExists(int v, int w) const
{
    /* Scan all existing edges from v to determine whether an edge to w exists.
     */
    const DGraphEdge *edge = vertices[v].outHead;
    while(edge) {
        if(edge->target == w) return true;
        edge = edge->nextOut;
    }
    return false;
}

/* --- reachable() ---
 * Test whether all vertices are reachable from the source vertex s.
 */
bool DGraph::reachable(int s) const
{
    int *stack = new int[nVertices];
    int tos = 0;
    
    int *visited = new int[nVertices];
    for(int i = 0; i < nVertices; i++) visited[i] = 0;
    
    int vertexCount = 0;
    visited[s] = 1;
    stack[tos++] = s;
    DGraphEdge *edge;
    int v, w;
    while(tos) {
        v = stack[--tos];
        vertexCount++;
        edge = vertices[v].outHead;
        while(edge) {
            w = edge->target;
            if(!visited[w]) {
                visited[w] = 1;
                stack[tos++] = w;
            }
            edge = edge->nextOut;
        }
    }
    
    delete [] stack;
    delete [] visited;
    
    return vertexCount == nVertices;
}


/* --- print() ---
 * Prints a text representation of the graph to the standard output.
 */
void DGraph::print() const
{
    const DGraphEdge *edge;
    
    printf("Graph (vertex: edge list) = \n");
    
    for(int i = 0; i < nVertices; i++) {
        printf("%d: ", i);
        edge = vertices[i].outHead;
        while(edge) {
            printf(" %d", edge->target);
            edge = edge->nextOut;
        }
        putchar('\n');
    }
    
    printf("Graph (vertex: edge{dist} list) = \n");
    
    for(int i = 0; i < nVertices; i++) {
        printf("%d: ", i);
        edge = vertices[i].outHead;
        while(edge) {
            printf(" %d{%d}", edge->target, edge->dist);
            edge = edge->nextOut;
        }
        putchar('\n');
    }
}
