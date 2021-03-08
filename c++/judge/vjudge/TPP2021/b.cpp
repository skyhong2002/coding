#include<bits/stdc++.h>
using namespace std;

int cal(int i){
    int o = i;
    while(i){
        o += (i%10);
        i /= 10;
    }
    return o;
}

int main(){
    int N;
    int cnt;
    cin >> cnt;
    while(cnt){
        cnt--;
        cin >> N;
        int min = 0;
        for(int i = 100000; i > 0; i--){
            if(cal(i)==N) min = i;
        }
        cout << min << "\n";
    }
}
