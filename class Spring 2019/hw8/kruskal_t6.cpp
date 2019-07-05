#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



class edge{
    
public:
    
    int v1,v2,cost;
    
};

vector<edge> e;

vector<edge> result; //MST에 포함된 엣지들. 오름차순으로 정렬됨.

long long Allcost; //MST의 엣지의 총합

int n,m;



class union_find{
    
public:
    
    vector<int> p; //부모를 저장하는 벡터
    
    vector<int> set_size; //그 집합에 몇개의 버텍스가 존재하는가
    
    
    
    void init(int cnt){ //그래프에 몇개의 노드가 존재하는지
        
        p.reserve(10001);
        
        for(int i=0; i<10001; i++)
            
        {
            
            p[i]=i;
            
            set_size.push_back(1);
            
        }
        
    }
    
    int find_root(int v){
        
        if(v == p[v]) //자신의 부모가 자신이면
            
            return v; //자신이 루트라는 의미이므로
        
        return find_root(p[v]);//자신의 부모를 타고 계속 검색
        
    }
    
    
    
    bool same_set(int v1,int v2){ //두개의 버텍스가 같은 집합인지 판단
        
        return find_root(v1) == find_root(v2);
        
    }
    
    
    
    void Union(int v1,int v2){ //v1과 v2의 각가 집합을 하나의 집합으로 합침
        
        int s1 = find_root(v1);
        
        int s2 = find_root(v2);
        
        if(s1 == s2) return;
        
        if(set_size[s1]<set_size[s2])
            
        {
            
            p[s1] = s2;
            
            set_size[s2] += set_size[s1];
            
        }else{
            
            p[s2] = s1;
            
            set_size[s1] += set_size[s2];
            
        }
        
    }
    
};



bool comp(const edge& e1,const edge& e2){
    
    return e1.cost<e2.cost; //엣지의 코스트를 기준으로 오름차순 정렬
    
}



void kruskal(){
    
    union_find uf;
    
    uf.init(n);
    
    for(auto k : e){
        
        if(!uf.same_set(k.v1,k.v2)){ //v1과 v2가 같은 집합이아닐때만
            
            uf.Union(k.v1, k.v2); //v1과 v2를 같은집합으로 만들고
            
            Allcost += k.cost;//MST의 cost를 증가시켜줌.
            
            result.push_back(k); //결과 MST벡터에 새로운 엣지(현재엣지) 추가
            
            if(result.size() == n-1) //엣지의 수가 버텍스의 수보다 1개 작으면 MST완성된것
                
                return;
            
        }
        
    }
    
}



int main()

{
    
    cin>>n>>m; //n은 버텍스 m은 엣지의 수
    
    for(int i=0; i<m; i++){
        
        edge ee;
        
        scanf("%d %d %d",&ee.v1,&ee.v2,&ee.cost);
        
        e.push_back(ee);
        
    }
    
    
    
    sort(e.begin(),e.end(),comp); //엣지의 비용 오름차순으로 정렬
    
    kruskal();
    
    
    
    cout<<Allcost<<endl;
    
    
    
    return 0;
    
}

