#include<iostream>
#include<algorithm>

using namespace std;

int map[400][400];
int INF = 100000;

int main(){
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < 400; i++){
        for (int j = 0; j < 400; j++){
            map[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++){
        int a,b,c;
        cin >> a >>b>> c;
        map[a- 1][b - 1] = c;
    }

    for (int k = 0; k < v; k++){
        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++){
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    int temp = INF;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (i == j)
                continue;
            if (map[i][j] != INF && map[j][i] != INF){
                temp = min(temp, map[i][j] + map[j][i]);
            }
        }
    }
    if (temp == INF)cout << -1 << endl;
    else cout << temp;
}
