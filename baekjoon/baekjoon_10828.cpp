//스택
//https://www.acmicpc.net/problem/10828

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string command;
stack<int> s;

int main(void){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> command;

        if(command == "push"){
            int a;
            cin >> a;
            s.push(a);
        } else if(command == "pop") {
            if(s.empty()){
                cout << -1 << '\n';
            } else {
                int a = s.top();
                cout << a << '\n';
                s.pop();
            }
        } else if(command == "size"){
            cout << s.size() << '\n';

        } else if(command == "empty"){
            if(s.empty()){
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if(command == "top"){
            int a = s.top();
            if(s.empty()){
                cout << -1 << '\n';
            } else {
                cout << a << '\n';
            }
        }
    }

    return 0;
}
