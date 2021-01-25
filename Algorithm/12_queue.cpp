//큐:가장 먼저 들어온 것이 먼저 나간다(FIFO)

#include<iostream>
#include<queue>

using namespace std;

int main(void){
    queue<int> q;
    q.push(7);
    q.push(5);
    q.push(4);
    //꺼내기
    q.pop();
    q.push(6);
    q.pop();
    
    //가장 윗쪽 데이터 출력하고 꺼내기
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}