// 자료구조
//스택 : 택배 상하차 - 가장 마지막에 들어온 데이터가 처리됨
// 큐 : 은행 창구


#include <iostream>
#include <stack>

using namespace std;


int main(void){
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(4);
    //꺼내기
    s.pop();
    s.push(6);
    s.pop();
    
    //가장 윗쪽 데이터 출력하고 꺼내기
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}