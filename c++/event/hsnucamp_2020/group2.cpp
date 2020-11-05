#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[4][4005];
    int N;
    map<int, int> dp[4];
    while(cin >> N){
        for(int i = 0; i < 4; i++){
            dp[i].clear();
            for(int j = 0; j < N; j++)
                cin >> a[i][j];
        }
        //cout << "Input ok\n";
        for(int j = 0; j < N; j++){
            dp[0][a[0][j]]++;
        }
        /*for(auto & k : dp[0]){
            cout << k.first << " : " << k.second << " ;\n";
        }*/
        for(int i = 1; i < 4; i++){
            for(int j = 0; j < N; j++){ //for all a[i][j]
                for(auto & k : dp[i-1]){
                    dp[i][a[i][j]+k.first] += k.second;
                }
            }
            /*for (auto & k : dp[i]){
                cout << k.first << " : " << k.second << " ;\n";
            }*/
        }
        for(auto & k : dp[3]){
            if(k.first==0){
                cout << k.second << "\n";
                break;
            }
        }
    }
}
