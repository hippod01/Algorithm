//KMP(Knuth-Morris-Pratt) 알고리즘
//대표적인 문자열(String) 매칭 알고리즘 : 특정한 글이 있을 때 그 글 안에서 하나의 문자열을 찾는 알고리즘
//모든 경우를 다 비교하지 않아도 부분 문자열을 찾을 수 있다.

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j=0;

    for(int i=1; i<patternSize; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];

        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern){

    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j=0;
    for(int i=0; i<parentSize; i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];

        }
        if(parent[i] == pattern[j]){
            if(j == patternSize -1){
                printf("%d번째에서 찾았습니다.\n",i-patternSize+2);
                j = table[j];
            } else{
                j++;
            }
        }
    }
}

int main(void){
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    // vector<int> table  = makeTable(pattern);
    // for(int i=0; i<table.size(); i++){
    //     printf("%d ", table[i]);

    // }

    KMP(parent, pattern);

    return 0;
}