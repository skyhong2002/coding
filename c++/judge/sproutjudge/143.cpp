//AC in once

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

// 3 1 4 1 5 9 2 6
//  4  4 1 5 9 2 6, cost 4
//   8   1 5 9 2 6, cost 12

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int cnt, numcnt, awful[105];
long long dp[105][105], dpscore[105][105];

long long solve(int a, int b){
	long long nowmin;
	if(a + 1 == b) return 0;
	else if(a + 2 == b) return awful[a] + awful[a+1];
	else if(dp[a][b] != 0) return dp[a][b];

	nowmin = solve(a,a+1) + solve(a+1,b);
	for (int n = a + 2; n < b; n++) nowmin = min(nowmin, solve(a,n) + solve(n,b));
	dp[a][b] = nowmin + dpscore[a][b];

	//cout << "dp: " << a << " " << b << " = " << nowmin << " + " << dpscore[a][b] << " = " << dp[a][b] << "\n";

	return dp[a][b];
}

void init(){
	for(int q = 1;q < numcnt + 1; q++){
		for(int j = q + 1;j <= numcnt + 1; j++){
			dpscore[q][j] = 0;
			dp[q][j] = 0;
			for(int k = q; k < j; k++) dpscore[q][j] += awful[k]; //dpscore = 從i加到j-1
		}
	}
	for(int q = 1; q < numcnt; q++) dp[q][q+1] = awful[q];
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long ans;

	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> numcnt;
		for (int j = 1; j <= numcnt; j++) cin >> awful[j];

		init();
		ans = solve(1, numcnt + 1);
		cout << ans << "\n";
	}

	

    return 0;
}