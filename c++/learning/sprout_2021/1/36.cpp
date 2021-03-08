#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    int a, b;
    stack<int> sk;

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a;
        if(a==1){
            cin >> b;
            sk.push(b);
        }
        if(a==2){
            if(sk.empty()){
                cout << "empty!\n";
                continue;
            }
            cout << sk.top() << "\n";
            sk.pop();
        }
    }
}
