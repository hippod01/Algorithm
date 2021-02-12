//https://www.acmicpc.net/problem/1654

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int n, k;
// int length[10000];

// int bs(){
//     long long ret = 0, cnt = 0;
//     long long left, right, mid;

//     left = 1;
//     right = INT_MAX;

//     while(left<=right){
//         mid = (right+left)/2;
//         cnt = 0;
//         for(int i=0; i<k; i++){
//             cnt += length[i] / mid;
//         }

//         if(cnt <n){
//             right = mid -1;
//         } else {
//             ret = mid;
//             left = mid +1;
//         }
//     }
//     return ret;
// }


// int main(void){

//     //K : 이미 가지고 있는 랜선의 개수
//     //N : 필요한 랜선의 개수 (모두 같은 길이)
//     cin >> k >> n;

//     int max = 0;
//     for(int i=0; i<k; i++){
//         //가지고 있는 랜선의 길이
//         cin >> length[i]; 
        
//     }

//     cout << bs() << '\n';
    

//     return 0;
// }

#include <iostream>

#include <algorithm>

using namespace std;

 

const int MAX = 10000;

 

int N, M;

long long electricLine[MAX];

 

bool possible(long long len)

{

        int cnt = 0;

        for (int i = 0; i < N; i++)

                 cnt += electricLine[i] / len;

       

        //조건 충족 여부

        if (cnt >= M)

                 return true;

        return false;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

 

        long long high = 0;

        for (int i = 0; i < N; i++)

        {

                 cin >> electricLine[i];

 

                 high = max(high, electricLine[i]);

        }

 

        long long result = 0;

        long long low = 1;

 

        //이분 탐색 진행

        while (low <= high)

        {

                 long long mid = (low + high) / 2;

                 if (possible(mid))

                 {

                         if (result < mid)

                                 result = mid;

                         low = mid + 1;

                 }

                 else

                         high = mid - 1;

        }

        cout << result << "\n";

        return 0;

}
