/*
 https://rosettacode.org/wiki/Dijkstra%27s_algorithm#C.2B.2B
 Solution follows Dijkstra's algorithm as described elsewhere. Data like min-distance, previous node, neighbors, are kept in separate data structures instead of part of the vertex. We number the vertexes starting from 0, and represent the graph using an adjacency list (vector whose i'th element is the vector of neighbors that vertex i has edges to) for simplicity.
 
 For the priority queue of vertexes, we use a self-balancing binary search tree (std::set), which should bound time complexity by O(E log V). Although C++ has heaps, without knowing the index of an element it would take linear time to find it to re-order it for a changed weight. It is not easy to keep the index of vertexes in the heap because the heap operations are opaque without callbacks. On the other hand, using a self-balancing binary search tree is efficient because it has the same log(n) complexity for insertion and removal of the head element as a binary heap. In addition, a self-balancing binary search tree also allows us to find and remove any other element in log(n) time, allowing us to perform the decrease-key step in logarithmic time by removing and re-inserting.
 
 We do not need to keep track of whether a vertex is "done" ("visited") as in the Wikipedia description, since re-reaching such a vertex will always fail the relaxation condition (when re-reaching a "done" vertex, the new distance will never be less than it was originally), so it will be skipped anyway.
 
 The time complexity of this algorithm is O(E log V), as described on Wikipedia. Each vertex is added to the priority queue at most once (re-ordering doesn't count as adding), because once it's in the priority queue, we only re-order it, never add it again. And when it's popped from the priority queue, that means we already have the real minimum distance to this vertex, so the relaxation condition will always fail in the future for this vertex, and it will never be added to the priority queue again. Therefore, we will only pop each vertex at most once from the priority queue, and the size of the priority queue is bounded by V (the number of vertexes).
 
 The outer loop executes once for each element popped from the priority queue, so it will execute at most once for each vertex, so at most V times. Each iteration of the outer loop executes one pop from the priority queue, which has time complexity O(log V). The inner loop executes at most once for each directed edge, since each directed edge has one originating vertex, and there is only at most one iteration of the outer loop for each vertex. Each iteration of the inner loop potentially performs one push or re-order on the priority queue (where re-order is a pop and a push), which has complexity O(log V). There is also the O(V) complexity for initializing the data structures. Combining these, we have a complexity of O(V log V + E log V), and assuming this is a connected graph, V <= E+1 = O(E), so we can write it as O(E log V).
 */

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>


typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = std::numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
    : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;


void DijkstraComputePaths(vertex_t source,
                          const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
    
    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());
        
        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(std::make_pair(min_distance[v], v));
                
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));
                
            }
            
        }
    }
}


std::list<vertex_t> DijkstraGetShortestPathTo(
                                              vertex_t vertex, const std::vector<vertex_t> &previous)
{
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}


int main()
{
    // remember to insert edges both ways for an undirected graph
    adjacency_list_t adjacency_list(6);
    // 0 = a
    adjacency_list[0].push_back(neighbor(1, 7));
    adjacency_list[0].push_back(neighbor(2, 9));
    adjacency_list[0].push_back(neighbor(5, 14));
    // 1 = b
    adjacency_list[1].push_back(neighbor(0, 7));
    adjacency_list[1].push_back(neighbor(2, 10));
    adjacency_list[1].push_back(neighbor(3, 15));
    // 2 = c
    adjacency_list[2].push_back(neighbor(0, 9));
    adjacency_list[2].push_back(neighbor(1, 10));
    adjacency_list[2].push_back(neighbor(3, 11));
    adjacency_list[2].push_back(neighbor(5, 2));
    // 3 = d
    adjacency_list[3].push_back(neighbor(1, 15));
    adjacency_list[3].push_back(neighbor(2, 11));
    adjacency_list[3].push_back(neighbor(4, 6));
    // 4 = e
    adjacency_list[4].push_back(neighbor(3, 6));
    adjacency_list[4].push_back(neighbor(5, 9));
    // 5 = f
    adjacency_list[5].push_back(neighbor(0, 14));
    adjacency_list[5].push_back(neighbor(2, 2));
    adjacency_list[5].push_back(neighbor(4, 9));
    
    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    DijkstraComputePaths(0, adjacency_list, min_distance, previous);
    std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPathTo(4, previous);
    std::cout << "Path : [";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << "]" << std::endl;
    
    return 0;
}
