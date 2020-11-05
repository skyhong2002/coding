#include<bits/stdc++.h>
using namespace std;

map<int, int> V;

int main(){
    int N, T,temp;
    while(cin >> N >> T){
        for(int i = 0; i < N; i++){
            cin >> temp;
            V[temp]= i;
        }
        for(int i = 0; i < N; i++){
            cout << T+1 << " ";
        }
        cout << "\n";
    }
}
