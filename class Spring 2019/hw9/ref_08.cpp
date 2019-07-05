/*
 https://rosettacode.org/wiki/Dijkstra%27s_algorithm#C.2B.2B
 Note that it is possible to use C++ built-in heaps (or the abstract std::priority_queue datatype) to implement this without changing the time complexity. Although the previous section noted that, without knowing the position of the element in the heap, it would take linear time to search for it in order to re-order it, the trick here is that we can insert the new updated element (with the vertex and updated lower distance), and simply leave the old element (with the vertex and old higher distance) in the priority queue without removing it, thereby eliminating the need to find it.
 
 Since we now leave multiple elements with the same vertex in the priority queue, in order to ensure we still only process a vertex's edges only once, we add a check when we retrieve an element from the priority queue, to check whether its distance is greater than the known minimum distance to that vertex. If this element is the most updated version for this vertex (i.e. the vertex's minimum distance has not been decreased since this element was added to the priority queue), then its distance must be equal to the current known minimum distance, since we only update the minimum distance in the decrease-key step. So if the element's distance is greater, we know that this is not the most updated version for this vertex -- i.e. we have already processed the edges for this vertex -- and we should ignore it.
 
 The only downside to this strategy is that many old "garbage" elements will be left in the priority queue, increasing its size, and thus also increasing the time it takes to push and pop, as well as increasing the number of times we have to pop. However, we argue that the time complexity remains the same.
 
 The main difference with the time complexity analysis for the previous algorithm is that here, we may add a vertex to the priority queue more than once. However, it is still true that the inner loop executes at most once for each directed edge. This is because in the outer loop, we added a check to ignore vertexes that we've already processed, so we will still only proceed down to the processing the edges at most once for each vertex. Therefore, the number of times that push is done on the priority queue (which happens at most once per iteration of the inner loop) is bounded by E, and the size of the priority queue is also bounded by E.
 
 The number of times the outer loop executes (the number of times an element is popped from the priority queue) is bounded by E, and in each iteration, the popping operation takes time complexity O(log E). The number of times the inner loop executes is also bounded by E, and the pushing operation inside it also takes time complexity O(log E). So in total, the time complexity is O(E log E). But not that, for a simple graph, E < V^2, so log E < 2 log V = O(log V). So O(E log E) can also be written as O(E log V), which is the same as for the preceding algorithm.
 */
#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <queue>
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
typedef std::pair<weight_t, vertex_t> weight_vertex_pair_t;

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
    // we use greater instead of less to turn max-heap into min-heap
    std::priority_queue<weight_vertex_pair_t,
    std::vector<weight_vertex_pair_t>,
    std::greater<weight_vertex_pair_t> > vertex_queue;
    vertex_queue.push(std::make_pair(min_distance[source], source));
    
    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.top().first;
        vertex_t u = vertex_queue.top().second;
        vertex_queue.pop();
        
        // Because we leave old copies of the vertex in the priority queue
        // (with outdated higher distances), we need to ignore it when we come
        // across it again, by checking its distance against the minimum distance
        if (dist > min_distance[u])
            continue;
        
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
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.push(std::make_pair(min_distance[v], v));
                
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
    std::cout << "Path : ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << std::endl;
    
    return 0;
}
