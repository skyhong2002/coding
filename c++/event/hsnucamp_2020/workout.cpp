#include<bits/stdc++.h>
using namespace std;

int d[200001];

int main(){
    int N;
    while(cin >> N){
        for(int i = 0; i < N; i++){
            cin >> d[i];
        }
        int con = 1, pre = 0;
        for(int i = 0; i < N; i++){
            if(d[i]==d[i+1]) pre++;
            else{
                if(pre>con) con = pre;
                pre = 0;
            }
        }
        cout << N - con << "\n";
    }
}
