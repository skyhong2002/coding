#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;
    deque<int> dq;
    dq.clear();
    while(cnt--){ 
        int s, k;
        cin >> s;
        if(s == 1){
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else if(s == 2){
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        else if(s == 3){
            cin >> k;
            dq.push_front(k);
        }
        else if(s == 4){
            cin >> k;
            dq.push_back(k);
        }
    }
}
