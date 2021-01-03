//크루스칼 알고리즘 : 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
// 최소 비용 신장 트리
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 // 부모 노드 찾는 함수
int getParent(int parent[], int x){
    
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 부모 노드 합치는 함수
void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a <b) parent[b] = a;
    else parent[a] = b;

}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return 1;
    else return 0;
}

//간선 정보 클래스 선언
class Edge{
    public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    // 정렬 기준
    bool operator <(Edge &edge){
        return this->distance < edge.distance;
    }
};

bool compare(Edge a, Edge b){
    return a.distance < b.distance;
}


int main(void){
    //노드
    int n = 7;
    //간선
    int m =11;

    vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

    //간선의 비용을 오름차순으로 정렬
    sort(v.begin(), v.end(), compare);

    // for(int i=0; i<v.size(); i++){
    //     cout << v[i].distance << ' ';
    // }

    

    //각 정점이 포함된 그래프가 어디인지 저장
    int set[n];

    for(int i = 1; i <=n; i++){
        set[i] = i;
    }

    

    for(int i=0; i<v.size(); i++){
        int x = findParent(set, v[i].node[0],v[i].node[1]);
        //  cout << x << '\n';
    }

    int sum = 0;

    for(int i=0; i <v.size(); i++){
        // 동일한 부모를 가지지 않는 경우(사이클이 발생하지 않는 경우)
        if(!findParent(set, v[i].node[0], v[i].node[1])){
            sum += v[i].distance;
            unionParent(set, v[i].node[0], v[i].node[1]);
        }
        // if(!findParent(set, v[i].node[0]-1, v[i].node[1]-1)){
        //     sum += v[i].distance;
        //     unionParent(set, v[i].node[0]-1, v[i].node[1]-1);
        // }
    }

    printf("%d\n", sum);

 
}