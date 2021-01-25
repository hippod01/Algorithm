//그리디 알고리즘 : 당장 눈 앞에 보이는 최적의 상황만을 쫓는 알고리즘
//대표적인 예제는 거스름 돈 문제 :  '무조건 더 큰 화폐 단위부터 거슬러 준다'
//정렬(Sort) 기법이 함께 사용되는 경우가 많다.


#include <iostream>

using namespace std;

int main(void){
    // 잔돈, 최소 잔돈 개수 result
    int n, result = 0;
    cin >> n;

    result += n/500;
    n %= 500;
    result += n/100;
    n %= 100;
    result += n/50;
    n %= 50;
    result += n/10;

    cout << result;
    return 0;
}