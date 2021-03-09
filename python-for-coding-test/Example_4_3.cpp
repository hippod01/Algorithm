#include <iostream>

using namespace std;

int n;
int dy[] = {1,2,-1,-2, 1, 2,-1,-2};
int dx[] = {2,1, 2, 1,-2,-1,-2,-1};


int main(void){
    string c;
    cin >> c;
    
    //행
    int y = (c[0]-'0')-48;
    //열
    int x = c[1]-'0';

    int cnt = 0;
    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(1<= nx && nx <= 8 && 1 <= ny && ny <= 8){
            // printf("nx : %d, ny : %d\n",nx,ny);
            cnt = cnt+1;
        }
    }

    cout << cnt << '\n';
    

    return 0;
}