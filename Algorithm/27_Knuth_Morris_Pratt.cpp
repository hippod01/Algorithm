//단순 비교 문자열 매칭 알고리즘(모든 경로를 다 확인) : O(N*M)

#include <iostream>

using namespace std;

int findString(string parent, string pattern){
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for(int i=0; i<=parentSize - patternSize; i++){
        bool finded = true;
        for(int j= 0; j<patternSize; j++){
            if(parent[i+j] != pattern[j]){
                finded = false;
                break;
            }
        }
        if(finded){
            return i;
        }
    }
    return -1;
}

int main(void){
    string parent = "hello World";
    string pattern = "llo W";

    int result = findString(parent, pattern);

    if(result == -1){
        printf("찾을 수 없습니다.");

    } else {
        printf("%d번째에서 찾았습니다.", result+1);
    }
}

