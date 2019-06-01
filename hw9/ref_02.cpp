// It takes infinite time to run. No problem at compile but run-time is infinite. Be careful to run this.


#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;


// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담아야 한다.
vector< pair<int, int> > adj[20001]; // 2차원 배열과 동일

vector<int> dijkstra(int src, int V, int E)
{
    // V만큼 배열을 INT_MAX로 초기화
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    priority_queue<pair<int, int> > pq;
    
    pq.push(make_pair(0, src));
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        
        pq.pop();
        
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
        if (dist[here] < cost)
            continue;
        
        // 인접한 정점들을 모두 검사.
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
                /*
                 여기서 -로 넣는 이유?
                 priority_queue STL은 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성
                 따라서 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하기 위함
                 */
            }
        }
    }
    
    
    return dist;
}

int main()
{
    // 정점, 간선의 개수 및 시작점
    int V, E, start;
    
    scanf("%d %d", &V, &E);
    scanf("%d", &start);
    
    V++; // 정점의 개수가 1부터 시작하면 V++해준다.
    
    for (int i = 0; i < E; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        
        adj[from].push_back(make_pair(to, val));
    }
    
    vector<int> ans = dijkstra(start, V, E);
    
    for (int i = 1; i < V; i++)
        ans[i] == INT_MAX ? printf("INF\n") : printf("%d\n", ans[i]);
    
    return 0;
}
