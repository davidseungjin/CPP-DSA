#include <iostream>
#include <vector>
#include <fstream>

#define INF 10000

using namespace std;

class Graph{
public:
    int vertexnumber;
    int edgenumber;
    int starting_node_index; // 정점의 수, 간선의 수, 시작 정점 번호
    vector<vector<int> > matrix;
    
public:
    Graph(string filename){
        int value;
        ifstream in(filename);  //cout << "    test    " << endl;
        in >> value;    //cout << "2    test    " << endl;
        vertexnumber = value;   //cout << "3    test    " << endl;
        matrix.assign(vertexnumber, vector<int>(vertexnumber,INF));
        cout << "Matrix Initialization" << endl;
        for (int i = 0 ; i < vertexnumber ; i++){
            cout << "[ ";
            for (int j = 0 ; j < vertexnumber; j++){
                cout << matrix[i][j] << "   ";}
            cout << " ]" << endl;}
        int src,dst,w;
        int count;
//        cout << "4    test    " << endl;
        for(;;){
            if(in>>src>>dst>>w){
                // 가중치 초기화
//                cout << "5    test    " << endl;
                matrix[src][dst] = w;
//                cout << "row src " << src <<
//                " and column dst " << dst << " is w " << w << endl;
//                cout << "6    test    " << endl;
                count++;
//                cout << "count" << count << endl;
                //matrix[v-1][u-1] = w; //무방향성 그래프일 경우 다음 코드를 추가한다. David: why v-1, u-1 are? I did u, v.
            }else{
                break;
            }
//            cout << "7    test    " << endl;
        }
        edgenumber = count;
//        cout << "8    test    " << endl;
        in.close();
    
        cout << "vertices are " << vertexnumber << endl;
        cout << "edges  are " << edgenumber << endl;
        
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << "[ ";
            for(int j=0; j < vertexnumber; j++){
                cout << matrix[i][j] << "\t";}
            cout << " ]" << endl;}
    
        dijkstra(1);
    }

//    int minDistance(int dist, bool check){
//        int min = INF;
//        int min_index;
//        for (int v = 0; v < vertexnumber; v++){
//            if(!check[v] && (min > dist[v])){
//                min_index = v;
//                min = dist[v];
//            }
//        }
//        return min_index;
//    }
//
//
    void dijkstra(int src){
        bool check[vertexnumber]; // 방문 여부, 최단 경로
        int dist[vertexnumber];
        vector<vector<int> > david_check;
    
        david_check.assign(vertexnumber, vector<int>(vertexnumber,false));
//        check.assign(vertexnumber, false);
        
        for(int i = 0; i < vertexnumber ; i++){
            dist[i] = INF;
            check[i] = false;
        }
        
        cout << "true false matrix FOR check." << endl;
        cout << "[ ";
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << check[i] << "\t";
        }cout << " ]" << endl;
        
        cout << "distance matrix FOR itself" << endl;
        cout << "[ ";
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << dist[i] << "\t";
        }cout << " ]" << endl;
        
        
        cout << "true false matrix: 2D David" << endl;
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << "[ ";
            for(int j=0; j < vertexnumber; j++){
                cout << david_check[i][j] << "\t";
            }
            cout << " ]" << endl;
        }
        
        
        
        dist[src] = 0;   // initial condition as well as self is zero.
        
        for(int i = 0; i < vertexnumber; i++){
            if(!david_check[src][i] && matrix[src][i] && (dist[i]>(dist[src]+matrix[src][i]))){
                
                dist[i] = dist[src] + matrix[src][i];
//              cout << "src " << src << " i " << i << " is " << 2 << endl;
        
                cout << "from " << src << " to " << i << " : dist[" << i << "] is " << dist[i] << endl;
                cout << "1st for-loop david_check status change \n";
                david_check[src][i] = true;
                
                for(int j = (vertexnumber-1); j >= vertexnumber; j--){
                    if(!david_check[i][j] && matrix[i][j] && (dist[j]>(dist[i]+matrix[i][j]))){
                        dist[j] = dist[i] + matrix[i][j];
                        cout << "from " << i << " to " << j << " : dist[" << j << "] is " << dist[j] << endl;
                        cout << "2nd for-loop david_check status change \n";
                        david_check[i][j] = true;
                        
                    }
                }
                
            }
        }

        // FROM HERE HERE HERE
        
        
        cout << "distance matrix FOR itself" << endl;
        cout << "[ ";
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << dist[i] << "\t";
        }cout << " ]" << endl;
        
        
        cout << "true false matrix: 2D David" << endl;
        for(int i = 0 ; i < vertexnumber ; i++){
            cout << "[ ";
            for(int j=0; j < vertexnumber; j++){
                cout << david_check[i][j] << "\t";
            }
            cout << " ]" << endl;
        }
        
//
//
//        for(int count = 0 ; count < (vertexnumber-1) ; count ++){
//            int u = minDistance(dist, check);
//
//            for(int v = 0 ; v < vertexnumber ; v++){
//                if(!check[v] && matrix[u][v] && (dist[u] != INF) && (dist[v] > (dist[u] + matrix[u][v]))){
//                    dist[v] = dist[u] + matrix[u][v];
//                }
//            }
//        check[u] = true;
//
//        }
//
//        for(int i = 0 ; i < vertexnumber; i++){
//
//
//
//        }
        

    }
    
   
    
};


    /*
    while(true)
    {
        int m = INF, N=-1;
        
        //최소 N번째 노드를 찾는다.
        for(int j=0;j<vertexnumber; j++)
        {
            if(!s[j] && (m>d[j]))
            {
                m = d[j];
                N = j;
            }
        }
        
        // m이 INF라는 얘기는 방문하지 않은 노드들의 d값이 전부 INF라는 뜻입니다.
        if(m == INF)
            break;
        
        s[N] = true; // N번째 노드를 방문.
        
        //d를 탐색하며 N번째 노드를 통해서 가는 길이 더 짧은 길이면 d를 더 짧은 길로 업데이트 한다.
        for(int j=0;j<vertexnumber;j++)
        {
            //j번째 노드가 이미 방문되었다면 d[j]는 이미 결정된 최소값이므로 변경하면 안된다.
            if(s[j]) continue;
            
            //N번째 노드와 인접 노드들을 돌며, N을 통해서 가는 거리를 via에 저장한다.
            unsigned int via = d[N] + graph[N][j];
            
            //N을 통해서 가는 거리가 더 짧으면, 그 인접 노드의 d[j](d까지 가는 거리의 최소거리)를 N을 통해서 가는 거리로 바꿔준다.
            if(d[j] > via)
                d[j] = via;
        }
    }
    return d;
     
     */
            
int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "smallgraph.txt";
                
    Graph a(input_file);
                
    return 0;
}
