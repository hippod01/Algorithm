//힙 구조를 활용한 다익스트라
//시간 복잡도 : O(N * log N)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 100000000;

//우선순위 큐 :저장한 순서에 구애받지 않고 우선순위에 따라 정렬되며, 
// 가장 우선순위가 높은 것부터 꺼낼 수 있다.
//각 요소를 ‘힙(heap)’이라는 자료구조의 형태로 저장

//간선 정보
vector<pair<int, int>> a[7];
//최소 비용
int d[7];


void dijkstra(int start){
    d[start] = 0;
    //힙구조
    priority_queue<pair<int, int>> pq;
    
    //값 넣음
    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int current = pq.top().first; 
        //cout << "current : " << current << ' ';
        //우선 순위 큐에서 큰값이 젤 위에 있음
        //짧은 것이 먼저 오도록 음수화(-)한다.
        int distance = -pq.top().second;
       // cout << "distance : " <<distance << '\n';

        pq.pop();

        // 최단 거리가 아닌 경우 스킵
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드 
			int next = a[current][i].first; 
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용 
			int nextDistance = distance + a[current][i].second;
			
           // cout << "next : " <<next << ' ';
            //cout << "nextDistance : " << nextDistance << '\n';

            // 기존의 최소 비용보다 더 저렴하다면 교체
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
                //짧은 것이 먼저 오도록 음수화(-)해서 넣어줌
				pq.push(make_pair(next, -nextDistance));
              //  cout << "d["<< next<< "] = " << d[next] << '\n';
			}
            
		}

    }

}


int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한
	for(int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// 결과를 출력합니다. 
	for(int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}