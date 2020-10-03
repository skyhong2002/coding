#include<bits/stdc++.h>
using namespace std;

long long find(int n, long long dp[]){
    if(dp[n]==0){
        dp[n] = find(n-1, dp) + find(n-2, dp);
        //cout << dp[n] << "is created.\n";
    }
    return dp[n];
}

int main(){
    
    long long dp[105] = {0};
    dp[0] = 1;
    dp[1] = 1;
    
    int n;
    while(cin>>n){
        cout << find(n, dp) << "\n";
    }
    return 0;
}
