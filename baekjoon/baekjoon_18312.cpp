//https://www.acmicpc.net/problem/18312
//구현

#include <iostream>
#include <string>

using namespace std;


//0분 --> 00분으로 변환
int main(void){

    //00:00:00 ~ N:59:59까지 K가 포함되는 모든 시각 카운팅 
    int n,k;
    cin >> n >> k;
    int cnt = 0;

    string sk = to_string(k);

    for(int h=0; h<=n; h++){
        for(int m=0; m<=59; m++){
            for(int s=0; s<=59; s++){
                string hour = to_string(h);
                if(h < 10) hour = "0" + hour;

                string minute = to_string(m);
                if(m < 10) minute = "0" + minute;
                
                string second = to_string(s);
                if(s < 10) second = "0" + second;

                if(hour.find(sk) != string::npos || minute.find(sk) != string::npos || second.find(sk) != string::npos){
                    cnt = cnt+1;
                }
                
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}