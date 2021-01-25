//바이너리 인덱스 트리 == 펜윅 트리(Fenwick Tree)
//2진 인덱스 구조를 활용하여 '구간 합' 문제를 효과적으로 해결해 줄 수 있는 자료구조

//세그먼트 트리와 비슷한 성능을 가지고 있지만 구현이 매우 간단하다는 특징 ( 더 개선된 메모리 성능 )
//비트(Bit) 연산을 활용하여 보다 직관적인 구조를 가지고 있어 이해하기 쉬움 

//마지막 비트  = 내가 저장하고 있는 값들의 개수라고 보면 트리 구조 만들어짐

#include <iostream>
#define NUMBER 6

using namespace std;

int tree[NUMBER];

//값을 갱신하는데 드는 시간 복잡도 O(logN)
void update(int i, int dif){
    while(i <= NUMBER){
        tree[i] += dif;
        // 마지막 비트만큼 더해가면서 이동
        i += (i & -i);
    }
}

//1~N까지의 합
int sum(int i){
    int result = 0;
    while(i>>0){
        result += tree[i];
        //마지막 비트만큼 빼가면서 이동
        i -= (i&-i);
    }
    return result;
}

//구간 합
int getSection(int start, int end) {
	return sum(end) - sum(start - 1);
}


int main(void){
    // for(int i=1; i<=16; i++){
    //     cout << i << "의 마지막 비트 : " << (i & -i) << '\n';
    // }

    update(1, 1);
	update(2, 2);
	update(3, 3);
	update(4, 4);
	update(5, 5);
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	update(3, -2);
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	update(5, 2);
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	// 1 ~ 5의 구간 합을 구합니다. 
	cout << getSection(1, 5) << '\n';
	
    return 0;
}




