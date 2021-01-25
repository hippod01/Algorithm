//정확하게 해시 값의 일치 여부를 검증하기 위해서 나머지 연산(MOD)를 사용하는 경우
//일반적으로 오버 플로우(Over Flow)가 발생해도 해시 값 자체는 동일하기 때문에 나머지 연산을 굳이 사용해주지 않아도 되긴 합니다.
//오버 플로우가 밥 먹듯이 발생해도 일반적인 연산 장치(CPU)의 경우 동일한 간격으로 음의 부호와 양의 부호를 왔다갔다 하므로 해시 값이 일치하는 것입니다. 
//하지만 더 안정적인 프로그램을 작성하고자 하실 때는 나머지 연산(MOD)를 입혀주시는 것을 추천

#include <iostream>

using namespace std;

void findString(string parent, string pattern){
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;

    for(int i=0; i<= parentSize - patternSize; i++){
        if(i==0){
            //hash값 set
            for(int j=0; j<patternSize; j++){
                //아스키코드 값 입력
                parentHash = parentHash + parent[patternSize - 1 - j] * power;
				patternHash = patternHash + pattern[patternSize - 1 - j] * power;
                //이의 제곱수 설정
                if(j < patternSize - 1) power = power * 403;
            }

        } else { 
            //MOD
            parentHash = 403 * (parentHash - parent[i - 1] * power) +parent[patternSize - 1 + i];
		}
		printf("해시 값 비교: %d %d\n", parentHash, patternHash);
        
        
        //해시값이 같을 때
        if(parentHash == patternHash){
            bool finded = true;
            for(int j =0; j <patternSize; j++){
                if(parent[i+j] != pattern[j]){
                    finded = false;
                    break;
                }
            }
            if(finded){
                printf("%d번째에서 발견했습니다. \n", i+1);
            }

        }

    }
}

int main(void){
    string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
    findString(parent, pattern);
    return 0;
}

