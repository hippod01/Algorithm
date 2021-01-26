//https://www.acmicpc.net/problem/1427

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    
    string n;
    cin >> n;

    sort(n.begin(), n.end(), greater<char>());
    cout << n;

}

