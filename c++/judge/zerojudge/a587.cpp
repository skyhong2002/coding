#include<bits/stdc++.h>
using namespace std;

int main(){

    int N, w[100], p[100], limit;

    while(cin >> N){
        for(int i=0; i<N; i++){
            cin >> w[i] >> p[i];
        }
        cin >> limit;
        
        int dp[10005]={0};
        for(int i=0; i<N; i++){
            for(int j=limit; j>0; j--){
                if(j-w[i]<0) continue;
                dp[j] = max(dp[j-w[i]]+p[i], dp[j]);
            }
            //cout << "Put No." << i << " item into stack.\n";
        }
            cout << dp[limit] << "\n";
    }
    

    return 0;
}
