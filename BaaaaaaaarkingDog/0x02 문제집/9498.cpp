#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int score;
    cin >> score;

    if( 90 <= score && 100 >= score ) cout << "A";
    else if( 80 <= score && 89 >= score ) cout << "B";
    else if( 70 <= score && 79 >= score ) cout << "C";
    else if( 60 <= score && 69 >= score ) cout << "D";
    else cout << "F";


    return 0;
}