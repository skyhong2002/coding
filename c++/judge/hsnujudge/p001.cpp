#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Ans;
    while(cin >> N){
        if(N == 4 || N == 7 ){
            cout << "This is Kongming's Trap!!!\n";
            continue;
        } 
        for(int i = 0; i<= 4; i++){
            if((N - i * 3)%5 == 0){
                Ans = i + (N - i * 3) / 5;
                cout << Ans << "\n";
            }
        }
    }
}
