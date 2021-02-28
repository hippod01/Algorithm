#include <iostream>

using namespace std;

int n;
int score[301];
int d[301];

void dp(int x){
    d[0] = score[0];
    d[1] = max(score[0]+score[1], score[1]);
    d[2] = max(score[0]+score[2], score[1]+score[2]);
    for(int i=3; i<n; i++){
        //두칸 오름, 한칸 오름
        d[i] = max(d[i-2]+score[i], d[i-3]+score[i-1]+score[i]);
    }
    cout << d[n-1] << '\n';
    
}

int main(void){

    cin >> n;
  
    for(int i=0; i<n; i++){
        cin >> score[i];
    }

    dp(n);

    return 0;
}