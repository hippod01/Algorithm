// 백준 문제 https://www.acmicpc.net/problem/1431

#include <iostream>
#include <algorithm>

using namespace std;

string a[1001];
int n;

int getSum(string a){
    int n = a.length(), sum =0;
    for(int i= 0; i <n; i++){
        //숫자인 경우에 더함
        if(a[i] - '0' <= 9 && a[i] -'0' >= 0){
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare(string a, string b){
    //길이 순서로 정렬
    if(a.length() != b.length()){

        return a.length() < b.length();

        //길이가 같으면 합을 비교해서 작은 합을 가지는 것이 먼저 온다(숫자인 경우)   
    } else if (a.length() == b.length()){
        int aSum = getSum(a);
        int bSum = getSum(b);

        //글자에 포함된 숫자의 합으로 정렬
        if(aSum != bSum){
            return aSum < bSum;
        }

    } else{
        return a <b;
    }
}


int main(void){

    //입력
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    //정렬
    sort(a, a+n, compare);

    //출력
    for(int i =0; i<n; i++){
        // 동일한 단어는 패스하고 출력
        if(i>0 && a[i] == a[i-1]) 
            continue;
        cout << a[i] << '\n';
    }
    return 0;
}