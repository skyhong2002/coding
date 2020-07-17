#include<bits/stdc++.h>
using namespace std;

vector<int> prime = {};
const int MAXN = 20005;
const int MINN = -1e9;
bool isp[MAXN];

void build(){
    isp[0]=isp[1]=false;
    for(int i=2; i<MAXN; i++) isp[i]=true;
    
    for(int i=2; i<MAXN; i++){
        if(!isp[i]) continue;
        prime.push_back(i);
        for(int j=i+i; j<MAXN; j+=i){
            isp[j]=false;
        }
    }
   // for(int i=0; i<100; i++) cout << i << ": " << (isp[i]?"Y":"N")<<"\n";
}

int main(){
    int n;cin >> n;
    build();
    
    vector<int> dp(n+1, MINN);
    dp[0]=0;
    for(auto i:prime){
        for(int j=n; j>0; j--){
            if(j-i<0) break;
            dp[j] = max(dp[j-i]+1,dp[j]);
        }
    }

    cout << max(dp[n], -1);
    return 0;
}
