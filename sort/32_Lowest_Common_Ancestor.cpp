//최소 공통 조상(LCA)
//트리(Tree) 구조에서 특정한 두 노드의 공통된 조상 중에서 가장 가까운 조상을 의미
//두 노드 사이의 거리를 빠르게 구하는 등 다양한 계산에 활용될 수 있다는 특징이 있다.

//일종의 DP, 반드시 이진 트리가 아니어도 괜찮음

// ※ 다이나믹 프로그래밍을 활용한 최소 공통 조상 알고리즘

// ① 모든 노드에 대한 깊이(Depth)를 구합니다.
// ② 모든 노드에 대한 2^i번째 부모 노드를 구합니다.
// ③ 최소 공통 조상을 찾을 두 노드를 설정합니다.
// ④ 두 노드의 깊이(Depth)가 동일하도록 거슬러 올라갑니다.
// ⑤ 최상단 노드부터 내려오는 방식으로 두 노드의 공통 부모를 찾아냅니다.

#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11 // 전체 노드의 갯수는 2^10개 이하임

using namespace std;

int n,m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

//1. 바로 윗 부모와 연결하는 함수
void dfs(int x, int depth){
    //방문처리
    c[x] = true;
    //root 정보
    d[x] = depth;
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(c[y]) continue;
        //부모 노드 정보
        parent[y][0] = x;
        dfs(y,depth+1);
    }
}

//2. 전체 부모 관계를 설정하는 함수
void setParent(){
    // root를 0으로 설정
    dfs(0,0); 
    for(int j=1; j<LOG; j++){
        for(int i=0; i<n; i++){
            //2^j번째의 부모 노드 저장
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }

    }
}

//3,4,5 최소 공통 조상을 찾는 함수
int LCA(int x, int y){
    // y가 더 깊도록 설정
    if(d[x] > d[y]){
        swap(x,y);
    }

    //두 노드의 깊이를 동일하도록 맞춤
    for(int i= LOG-1; i>=0; i--){
        if(d[y] - d[x] >= (1 << i)){
            y = parent[y][i];
        }
    }

    //부모가 같은 경우 반환
    if(x == y) return x;

    for(int i= LOG-1; i>=0; i--){
        //조상을 향해 거슬러 올라감
        //부모가 동일하지 않는 시기를 찾음
        if(parent[x][i] != parent[y][i]){
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    //부모가 찾고자 하는 조상
    return parent[x][0];
}

int main(void){
    n = 21;
	// 0과 1을 연결합니다.
	a[0].push_back(1);
	a[1].push_back(0);
	// 0과 2를 연결합니다.
	a[0].push_back(2);
	a[2].push_back(0);
	// 1과 3을 연결합니다.
	a[1].push_back(3);
	a[3].push_back(1);
	// 1과 4를 연결합니다.
	a[1].push_back(4);
	a[4].push_back(1);
	// 2와 5을 연결합니다.
	a[2].push_back(5);
	a[5].push_back(2);
	// 2와 6을 연결합니다.
	a[2].push_back(6);
	a[6].push_back(2);
	// 3과 7을 연결합니다.
	a[3].push_back(7);
	a[7].push_back(3);
	// 3과 8을 연결합니다.
	a[3].push_back(8);
	a[8].push_back(3);
	// 4와 9를 연결합니다.
	a[4].push_back(9);
	a[9].push_back(4);
	// 4와 10을 연결합니다.
	a[4].push_back(10);
	a[10].push_back(4);
	// 4와 11을 연결합니다.
	a[4].push_back(11);
	a[11].push_back(4);
	// 8과 12를 연결합니다.
	a[8].push_back(12);
	a[12].push_back(8);
	// 8과 13을 연결합니다.
	a[8].push_back(13);
	a[13].push_back(8);
	// 9와 14를 연결합니다.
	a[9].push_back(14);
	a[14].push_back(9);
	// 10과 15를 연결합니다.
	a[10].push_back(15);
	a[15].push_back(10);
	// 13과 16을 연결합니다.
	a[13].push_back(16);
	a[16].push_back(13);
	// 13과 17을 연결합니다.
	a[13].push_back(17);
	a[17].push_back(13);
	// 14와 18을 연결합니다.
	a[14].push_back(18);
	a[18].push_back(14);
	// 15와 19를 연결합니다.
	a[15].push_back(19);
	a[19].push_back(15);
	// 17과 20을 연결합니다.
	a[17].push_back(20);
	a[20].push_back(17);

	setParent();

    cout << "5와 7의 LCA: " << LCA(5, 7) << '\n';
	cout << "15와 20의 LCA: " << LCA(15, 20) << '\n';
	cout << "16과 17의 LCA: " << LCA(16, 17) << '\n';
	cout << "10과 9의 LCA: " << LCA(10, 9) << '\n';
	cout << "3과 17의 LCA: " << LCA(3, 17) << '\n';
	return 0;

}