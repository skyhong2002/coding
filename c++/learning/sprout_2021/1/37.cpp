#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    queue<int> q;
    int N;
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a==1){
            cin >> b;
            q.push(b);
        }
        if(a==2){
            if(q.empty()){
                cout << "empty!\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
    }
}
